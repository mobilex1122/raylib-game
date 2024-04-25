#ifndef MINMAX_H
#define MINMAX_H

inline float min(float a,float b) { return a > b ? b : a; };
inline int mini(int a,int b) { return a > b ? b : a; };
inline float max(float a,float b) { return a < b ? b : a; };
inline int maxi(int a,int b) { return a < b ? b : a; };
#endif