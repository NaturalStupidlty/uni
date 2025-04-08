import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLabel, QFileDialog, QComboBox
import plotly.graph_objs as go
from plotly.subplots import make_subplots
from PyQt5.QtWebEngineWidgets import QWebEngineView
from astronify.series import SoniSeries
import lightkurve
import tempfile
import qdarktheme
from PyQt5.QtCore import QUrl


class LightCurveSonificationApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Light Curve Sonification')
        self.setGeometry(100, 100, 1200, 800)

        # Main layout
        self.layout = QVBoxLayout()

        # Combo box
        self.lightCurveSelector = QComboBox()
        self.lightCurveSelector.setStyleSheet("QComboBox {padding-left: "
                                              "540px;}")
        self.lightCurveSelector.addItems(
            ['KIC 11804465',
             'KIC 10264202',
             'KIC 3733346']
        )

        # Buttons
        self.loadButton = QPushButton('Load Light Curve')
        self.sonifyButton = QPushButton('Sonify')
        self.saveButton = QPushButton('Save as MIDI')
        self.playButton = QPushButton('Play Sonification')
        self.stopButton = QPushButton('Stop Sonification')

        # Labels
        self.statusLabel = QLabel('Status: Ready')
        self.statusLabel.setMaximumHeight(self.statusLabel.sizeHint().height() + 10)

        # Plot area
        self.plotWidget = QWebEngineView()

        # Add widgets to layout
        self.layout.addWidget(self.lightCurveSelector)
        self.layout.addWidget(self.loadButton)
        self.layout.addWidget(self.sonifyButton)
        self.layout.addWidget(self.saveButton)
        self.layout.addWidget(self.playButton)
        self.layout.addWidget(self.stopButton)
        self.layout.addWidget(self.statusLabel)
        self.layout.addWidget(self.plotWidget)

        # Set layout
        self.setLayout(self.layout)

        # Connect buttons
        self.loadButton.clicked.connect(self.load_light_curve)
        self.sonifyButton.clicked.connect(self.sonify_data)
        self.saveButton.clicked.connect(self.save_midi)
        self.playButton.clicked.connect(self.play_sonification)
        self.stopButton.clicked.connect(self.stop_sonification)

        # Initialize light curve and sonification object
        self.kep12b_lc = None
        self.kep12b_obj = None

    def load_light_curve(self):
        self.statusLabel.setText("Status: Loading light curve...")
        target_id = self.lightCurveSelector.currentText()
        self.kep12b_lc = (lightkurve.search_lightcurve(target_id, quarter=1)
                          .download_all().stitch())

        time = self.kep12b_lc['time'].jd
        flux = self.kep12b_lc['flux']

        fig = make_subplots(rows=1, cols=1, subplot_titles=('Light Curve',))
        fig.add_trace(go.Scatter(x=time, y=flux, mode='lines', name='Flux'))
        fig.update_layout(
            title='Light Curve',
            xaxis_title='Time (JD)',
            yaxis_title='Flux',
            height=600,
            width=1100,
            plot_bgcolor='#1e1e1e',
            paper_bgcolor='#1e1e1e',
            font=dict(color='#FFFFFF'),
            xaxis=dict(showgrid=False, color='#FFFFFF'),
            yaxis=dict(showgrid=False, color='#FFFFFF'),
        )

        # Save plot to temporary HTML file
        with tempfile.NamedTemporaryFile(delete=False, suffix=".html") as tmp:
            fig.write_html(tmp.name)
            self.plotWidget.setUrl(QUrl(f"file://{tmp.name}"))

        self.statusLabel.setText("Status: Light curve loaded")

    def sonify_data(self):
        if self.kep12b_lc is None:
            self.statusLabel.setText("Status: Load a light curve first!")
            return

        self.statusLabel.setText("Status: Sonifying data...")
        self.kep12b_obj = SoniSeries(self.kep12b_lc)
        self.kep12b_obj.sonify()
        self.statusLabel.setText("Status: Sonification complete")

    def save_midi(self):
        if self.kep12b_obj is None:
            self.statusLabel.setText("Status: Sonify the data first!")
            return

        options = QFileDialog.Options()
        midi_file, _ = QFileDialog.getSaveFileName(self, "Save MIDI File", "",
                                                   "MIDI Files (*.mid);;All Files (*)",
                                                   options=options)
        if midi_file:
            if not midi_file.endswith('.mid'):
                midi_file += '.mid'
            self.kep12b_obj.write(midi_file)
            self.statusLabel.setText(f"Status: MIDI saved to {midi_file}")

    def play_sonification(self):
        if self.kep12b_obj is None:
            self.statusLabel.setText("Status: Sonify the data first!")
            return
        self.kep12b_obj.play()
        self.statusLabel.setText("Status: Playing sonification")

    def stop_sonification(self):
        if self.kep12b_obj is None:
            self.statusLabel.setText("Status: Nothing to stop!")
            return
        self.kep12b_obj.stop()
        self.statusLabel.setText("Status: Sonification stopped")

    def closeEvent(self, event):
        if self.kep12b_obj is not None:
            try:
                self.kep12b_obj.stop()
            except Exception as e:
                print(f"Error while stopping sonification: {e}")
        event.accept()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    qdarktheme.setup_theme("auto")
    window = LightCurveSonificationApp()
    window.show()
    try:
        sys.exit(app.exec_())
    except SystemExit:
        print("Application closed successfully.")
