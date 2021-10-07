/* Determine whether arguments be added without overflow */
int tadd_ok(int x, int y){
    int sum = x + y;
    //正溢出只有当x>0,y>0但sum<=0
    bool pos_overflow = x > 0 && y > 0 && sum <= 0;
    //负溢出只有当x < 0,y < 0但sum >=0;
    bool neg_overflow = x < 0 && y < 0 && sum >= 0;
    return !pos_overflow && !neg_overflow;
}
