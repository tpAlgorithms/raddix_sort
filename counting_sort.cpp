#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

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

  // {1,1,1,0,2} -> {1,2,3,3,5}
  // {1,1,1,0,2} -> {0,1,2,3,3}
  int sum = 0;
  for (int i = 0; i < abc_size; ++i) {
    int tmp = cnt[i];
    cnt[i] = sum;
    sum += tmp;
  }
/*
  int j = 0;
  for (int i = 0; i < abc_size; ++i) {
    for (int k = 0; k < cnt[i]; ++k, ++j) {
//      a[j] = i;
      res[j] = ... a[l];        
    }
  }
  */
  int *res = new int[n];
  for (int i = 0; i < n; ++i) {
    res[cnt[_get_digit(a[i])]] = a[i];
    ++cnt[_get_digit(a[i])];
  }
  
  memcpy(a, res, n*sizeof(int));
  
  delete [] res;
  delete [] cnt;

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
