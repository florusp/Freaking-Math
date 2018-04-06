#include"Display.h"
#include"Instruction.h"
#include"WorkingWithLevel.h"
#include"CustomizeGame.h"


int main()
{
	So so;
	Toantu toantu;
	Diem diem;
	Capdo capdo;
	TraLoi traloi;
	DieuKienTroChoi dieukien;

	instruction(dieukien);
	//resizeConsole(500, 270);
	while (dieukien.flag == 1)
	{
		while (dieukien.flag == 1)
		{
			display(so, toantu, diem, capdo, dieukien, traloi);
			updateLevel(diem, capdo);
			dieukien.timeCounter = 2;
		}
		resetLevel(diem, capdo);
		option(dieukien);
	}
}
