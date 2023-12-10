int main() {
  { using namespace metric;
    cout << kilo(1) << endl;
  }
  { using namespace binary;
    cout << kilo(1) << endl;
  }
  system("pause"); return 0;
}