#include <iostream>
#include <vector>
#include <cstdio>

int get_digit(const int &data) {
  return data % 10;
}

const int abc_size = 10;

void counting_sort(int *a, int n, int(&_get_digit)(const int &)) {
  
  int *cnt = new int[abc_size];
  
  for (int i = 0; i < abc_size; ++i) {
    cnt[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    ++cnt[_get_digit(a[i])];
  }

  int j = 0;
  for (int i = 0; i < abc_size; ++i) {
    for (int k = 0; k < cnt[i]; ++k, ++j) {
      a[j] = i;
    }
  }
}


int main() {
  
  std::vector<int> data;
  
  for (;;) {
    int value;
    if (scanf("%d", &value)!=1) {
      break;
    }
    data.push_back(value);
  }

  counting_sort(&data[0], data.size(), get_digit);

  for (int i = 0; i < data.size(); ++i) {
    printf("%d\n", data[i]);
  }

  return 0;
}
