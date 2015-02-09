public interface MapInt {
  public int map(int e);
}

class IdentityMapper implements MapInt {
  public int map(int e) {
    return e;
  }
}
