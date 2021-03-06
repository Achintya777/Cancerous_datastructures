 // Segment Tree with lazy propagation for range sum query and  range updates
int n ;
ll st[4*mxN+1], lz[4*mxN+1];
void app(int i, ll x, int l, int r) {
  st[i]+=x*(r-l+1);
  lz[i]+=x;
}
void psh(int i, int l, int m, int r) {
  app(2*i, lz[i], l, m);
  app(2*i+1, lz[i], m+1, r);
  lz[i]=0;
}
void upd(int l1, int r1, ll x, int i=1, int l2=1, int r2=n) {
  if(l1<=l2&&r2<=r1) {
    app(i, x, l2, r2);
    return;
  }
  int m2=(l2+r2)/2;
  psh(i, l2, m2, r2);
  if(l1<=m2)
    upd(l1, r1, x, 2*i, l2, m2);
  if(m2<r1)
    upd(l1, r1, x, 2*i+1, m2+1, r2);
  st[i]=st[2*i]+st[2*i+1];
}
ll qry(int l1, int r1, int i=1, int l2=1, int r2=n) {
  if(l1<=l2&&r2<=r1)
    return st[i];
  int m2=(l2+r2)/2;
  psh(i, l2, m2, r2);
  return (l1<=m2?qry(l1, r1, 2*i, l2, m2):0)+(m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):0);
}
