


struct get_digit_t {
  get_digit_t(int divider_, int base_)
    : divider(divider_)
      base(base_)
  {} 

  int operator ()(const int &data) {return (data / divider) % base };
  int divider;
  int base;
};

void lsd(int *a, int n) {

  int divider = 1;
  for (int k = 0; k < 10; ++k, divider *= 10) {
    get_digit_t get_digit(divider, 10);
    counting_sort(a, n, get_digit);  
  }
}

struct get_char_t {

}

void msd(char **a, int n, int k = 0) {
  const int abc_size = 256;
  int *groups = new int[abc_size + 1];
  groups[abc_size] = n;
  
  
  get_cahr_t get_char(k);

  counting_sort(a, n, get_char, groups); 

  for (int i = 0; i < abc_size; ++i) {
    int group_size = groups[i + 1] - groups[i];
    if (group_size > 1) {
      msd(&a[groups[i]], group_size, k + 1);
    }
  }
  
  delete [] groups;
}

int main() {


  return 0;
}
