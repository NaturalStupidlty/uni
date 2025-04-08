import time
import numpy as np
import matplotlib.pyplot as plt

import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset, random_split

from sklearn.datasets import load_digits

import gradio as gr
from PIL import Image, ImageOps


class FeedForwardNN(nn.Module):
    def __init__(self, input_size, hidden_sizes, output_size, activation_fn):
        """
        Constructs a feed-forward network.
        :param input_size: number of input neurons.
        :param hidden_sizes: list with number of neurons in each hidden layer.
        :param output_size: number of output neurons.
        :param activation_fn: activation function class (e.g. nn.ReLU).
        """
        super(FeedForwardNN, self).__init__()
        layers = []
        in_size = input_size
        for h in hidden_sizes:
            layers.append(nn.Linear(in_size, h))
            layers.append(activation_fn())
            in_size = h
        layers.append(nn.Linear(in_size, output_size))
        self.net = nn.Sequential(*layers)

    def forward(self, x):
        return self.net(x)

    @property
    def device(self):
        return next(self.parameters()).device


def train_model(
    model,
    criterion,
    optimizer,
    train_loader,
    val_loader,
    device,
    num_epochs=50,
    task="binary",
):
    model.to(device)
    train_losses = []
    val_losses = []
    start_time = time.time()

    for epoch in range(num_epochs):
        model.train()
        running_loss = 0.0
        correct_train = 0
        total_train = 0

        for inputs, labels in train_loader:
            inputs = inputs.to(device)
            labels = labels.to(device)

            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item() * inputs.size(0)

            if task == "binary":
                preds = (torch.sigmoid(outputs) > 0.5).float()
            else:
                preds = torch.argmax(outputs, dim=1)
                labels = labels.long().squeeze() if labels.dim() > 1 else labels.long()

            correct_train += (preds == labels).sum().item()
            total_train += inputs.size(0)

        epoch_loss = running_loss / total_train
        train_losses.append(epoch_loss)
        train_acc = correct_train / total_train

        model.eval()
        running_val_loss = 0.0
        correct_val = 0
        total_val = 0
        with torch.no_grad():
            for inputs, labels in val_loader:
                inputs = inputs.to(device)
                labels = labels.to(device)
                outputs = model(inputs)
                loss = criterion(outputs, labels)
                running_val_loss += loss.item() * inputs.size(0)
                if task == "binary":
                    preds = (torch.sigmoid(outputs) > 0.5).float()
                else:
                    preds = torch.argmax(outputs, dim=1)
                    labels = (
                        labels.long().squeeze() if labels.dim() > 1 else labels.long()
                    )
                correct_val += (preds == labels).sum().item()
                total_val += inputs.size(0)
        val_loss = running_val_loss / total_val
        val_losses.append(val_loss)
        val_acc = correct_val / total_val

        print(
            f"Epoch {epoch + 1}/{num_epochs} | Train Loss: {epoch_loss:.4f} | Train Acc: {train_acc:.4f} | "
            f"Val Loss: {val_loss:.4f} | Val Acc: {val_acc:.4f}"
        )

    duration = time.time() - start_time
    print(f"Training duration: {duration:.2f} seconds\n")
    return train_losses, val_losses, duration


def evaluate_model(model, test_loader, device, task="binary"):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for inputs, labels in test_loader:
            inputs = inputs.to(device)
            labels = labels.to(device)
            outputs = model(inputs)
            if task == "binary":
                preds = (torch.sigmoid(outputs) > 0.5).float()
            else:
                preds = torch.argmax(outputs, dim=1)
                labels = labels.long().squeeze() if labels.dim() > 1 else labels.long()
            correct += (preds == labels).sum().item()
            total += inputs.size(0)
    acc = correct / total
    print(f"Test Accuracy: {acc:.4f}\n")
    return acc


def plot_loss(train_losses, val_losses, title="Loss Curve"):
    plt.figure()
    plt.plot(train_losses, label="Train Loss")
    plt.plot(val_losses, label="Validation Loss")
    plt.xlabel("Epoch")
    plt.ylabel("Loss")
    plt.title(title)
    plt.legend()
    plt.show()


def main_digits(num_epochs=50, batch_size=128):
    print("=== Running Digit Classification Task ===")
    digits = load_digits()
    X = digits.data.astype(np.float32)  # shape: (n_samples, 64)
    y = digits.target.astype(np.int64)

    X = torch.tensor(X)
    y = torch.tensor(y)

    dataset = TensorDataset(X, y)
    test_size = int(0.25 * len(dataset))
    train_size = len(dataset) - test_size
    train_dataset, test_dataset = random_split(dataset, [train_size, test_size])

    val_size = int(0.2 * len(train_dataset))
    train_size_final = len(train_dataset) - val_size
    train_dataset, val_dataset = random_split(
        train_dataset, [train_size_final, val_size]
    )

    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False)
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    hidden_layers = [256, 128, 64]
    activation_fn = nn.ReLU
    optimizer_name = "Adam"

    model = FeedForwardNN(
        input_size=64,
        hidden_sizes=hidden_layers,
        output_size=10,
        activation_fn=activation_fn,
    )

    criterion = nn.CrossEntropyLoss()

    if optimizer_name == "SGD":
        optimizer = optim.SGD(model.parameters(), lr=0.1)
    elif optimizer_name == "Adam":
        optimizer = optim.Adam(model.parameters(), lr=0.01)
    else:
        optimizer = optim.RMSprop(model.parameters(), lr=0.01)

    print(
        f"Parameters: Optimizer={optimizer_name}, Activation={activation_fn.__name__}, Hidden Layers={hidden_layers}"
    )
    train_losses, val_losses, duration = train_model(
        model,
        criterion,
        optimizer,
        train_loader,
        val_loader,
        device,
        num_epochs=num_epochs,
        task="multiclass",
    )
    test_acc = evaluate_model(model, test_loader, device, task="multiclass")
    plot_loss(
        train_losses,
        val_losses,
        title=f"Digit Classification Loss ({optimizer_name}, {activation_fn.__name__}, {hidden_layers})",
    )

    return model, test_acc, duration


# Train the model and get the scaler (fitted on digits data)
model, test_acc, training_duration = main_digits(num_epochs=50, batch_size=128)

# -------------------------------
# Gradio app for interactive testing
# -------------------------------


def predict_digit(image):
    """
    Given an image from the Gradio canvas, preprocess it to 8x8, and predict the digit.
    """
    if image.ndim == 3:
        image = np.mean(image, axis=2)
    im = Image.fromarray(image.astype(np.uint8))
    # Resize to 8x8 (digits dataset images are 8x8).
    im = im.resize((8, 8), Image.LANCZOS)
    im = ImageOps.invert(im)
    im_arr = np.array(im).astype(np.float32).flatten()
    tensor = torch.tensor(im_arr, dtype=torch.float32).unsqueeze(0)
    # Run the model.
    model.eval()
    with torch.no_grad():
        output = model(tensor.to(model.device))
        # Return a dictionary of logits for each class (Gradio Label interprets this as probabilities).
    return {str(i): float(output[0, i].item()) for i in range(10)}


# Create the Gradio interface.
interface = gr.Interface(
    fn=predict_digit,
    inputs=gr.Image(
        image_mode="L",
        source="canvas",
        tool="select",
        type="numpy",
        label="Draw a digit",
        height=512,
        width=512,
    ),
    outputs=gr.Label(num_top_classes=3, label="Predicted Digit"),
    title="Digit Recognition",
    description="Draw a digit on the canvas below and the model will predict which digit it is.",
)

# Launch the Gradio app.
interface.launch()
