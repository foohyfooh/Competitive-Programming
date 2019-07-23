struct BinaryCounter {
  bool* counter;
  int size;
  BinaryCounter(int N) : size{N} {
    counter = (bool*) calloc(N + 1, sizeof(bool));
  }
  bool increment(){
    for(int i = size ; i > 0; i--)
      if((counter[i] = !counter[i])) return true;
    return false;
  }
  bool operator[] (int i) const {
  	return counter[i];
  }
  bool& operator[](int i){
  	return counter[i];
  }
};
