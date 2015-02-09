public class RadixSort {
  public static int[] sort(int[] arr, int digits) {
    for (int i = 0; i < digits; i++) {
      MapInt mapper = new DigitMapper(i);
      arr = CountingSort.sort(arr, 9, mapper);
    }
    return arr;
  }
}

class DigitMapper implements MapInt {
  public DigitMapper(int digit) {
    this.digit = digit;
  }

  public int map(int e) {
    int d = this.digit;
    while (d-- > 0) {
      e /= 10;
    }
    return e % 10;
  }

  private int digit;
}
