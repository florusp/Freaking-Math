#ifndef WorkingWithScore_h
#define WorkingWithScore_h

#include"Objects.h"

/*cong diem neu tra loi dung*/
void addScore(DieuKienTroChoi &dieukien, Diem &diem);

/*tra ve diem cao nhat*/
void returnBestScore(DieuKienTroChoi &dieukien, Diem &diem);

/*them diem cao nhat vao file*/
void addBestScore(Diem &diem);

/*doc diem cao nhat tu file*/
void readBestScore(Diem &diem);
#endif // !WorkingWithScore_h
