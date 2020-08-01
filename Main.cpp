#pragma once
#include "ThuVien.h"

char tdChinh[soItem_MenuChinh][100] = { "1. Quan ly may bay                                     ",
										 "2. Quan ly chuyen bay                                 ",
										 "3. Dat ve/Huy ve                                      ",
										 "4. Danh sach hanh khach thuoc 1 chuyen bay            " ,
										 "5. Danh sach cac chuyen bay khoi hanh trong dd/mm/yyyy",
										 "6. Danh sach ve con trong cua chuyen bay X            ",
										 "7. Ket thuc"
};
char tdMayBay[soItem_MenuMB][100] = { "1. Them may bay",
										 "2. Xoa may bay",
										 "3. Hieu chinh may bay",
										 "4. Tro ve"
};
char tdChuyenBay[soItem_MenuCB][100] = { "1. Them chuyen bay",
										 "2. Xoa chuyen bay",
										 "3. Hieu chinh chuyen bay",
										 "4. Tro ve"
};

int main() {
	LIST_MB lstMB;
	PTRChuyenBay lstCB;
	initCB(lstCB);

	int loadmb = loadMB(lstMB);
	int loadcb = loadCB(lstCB);
	int chon;
	int exit = 1;
	while (exit) {
		Normal();
		system("cls");
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
		case 1:
		{
			int chonMB;
			int exit1 = 1;
			Normal();
			system("cls");
			
			while (exit1) {
				quickSortMB(lstMB, 0, lstMB.n - 1);
				show_MB(lstMB);
				chonMB = menuDong_MayBay(tdMayBay);
				
				switch (chonMB)
				{
				case 1:
				{
					mayBay mb = createMB(lstMB, mb);
					int a = insert_MB(lstMB, mb);
					if (a == 1) {
						hienThongBao("Them thanh cong!");
						int save = saveMB(lstMB);
					}
					Normal();
					system("cls");
					break;
					
				}
				case 2:
				{
					char ma[20] = {'\0'};
					int tontai = -1;
					do
					{
						strcpy(ma, gdTimMa(lstMB, 0, "XOA MAY BAY"));
						tontai = search_MB(lstMB, ma);
						if (tontai == -1)
							hienThongBao("Khong tim thay so hieu nay!");
						else break;
					} while (true);
					
					int chucnang = khungXoaMB();
					if (chucnang == 1)
					{
						int xoa = delete_MB(lstMB, tontai);
						if (xoa == 1) {
							//veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGDS_D);
							
							hienThongBao("Xoa thanh cong!");
							int save = saveMB(lstMB);
						}
						else {
							hienThongBao("Xoa that bai!");
						}
					}
					else
					{
						hienThongBao("Da huy xoa!");
					}
//					int xoa = delete_MB(lstMB, tontai);
//					if (xoa == 1) {
//						//veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGDS_D);
//						
//						hienThongBao("Xoa thanh cong!");
//						int save = saveMB(lstMB);
//					}
//					else {
//						hienThongBao("Xoa that bai!");
//					}
					Normal();
					system("cls");
					break;
					
				}
				case 3:
				{
					char ma[20] = { '\0' };
					int tontai = -1;
					do
					{
						strcpy(ma, gdTimMa(lstMB, 0, "HIEU CHINH MAY BAY"));
						tontai = search_MB(lstMB, ma);
						if (tontai == -1)
							hienThongBao("Khong tim thay so hieu nay!");
						else break;
					} while (true);

					int sua = hieuChinh_MB(lstMB, tontai);
					if (sua == 1) {
						hienThongBao("Hieu chinh thanh cong!");
						int save = saveMB(lstMB);
					}
					else {
						hienThongBao("Hieu chinh that bai!");
					}
					Normal();
					system("cls");
					break;
					
				}
				case soItem_MenuMB:
				{
					exit1 = 0;
					break;
				}
					
				}
			}
			break;
		}
		case 2:
		{
			int chonCB;
			int exit2 = 1;
			Normal();
			system("cls");
			while (exit2)
			{
				showCB(lstCB);
				chonCB = menuDong_ChuyenBay(tdChuyenBay);
				switch (chonCB)
				{
				case 1:
				{
					CHUYENBAY cb;
					cb = createCB(lstCB, cb, lstMB);
					insert_OrderNodeCB(lstCB, cb);
					int save = saveCB(lstCB);
					
					char c = getch();
					if (c == 13) {
						Normal();
						system("cls");
						break;
					}
					break;
				}
				case 3:
				{
					char ma[20] = {'\0'};
					//PTRChuyenBay p = searchBin_CB(lstCB, ma);
					PTRChuyenBay p;
					do
					{
						strcpy(ma, gdTimMa(lstMB, 0, "HIEU CHINH CHUYEN BAY"));
						p = searchBin_CB(lstCB, ma);
						if (p == NULL)
						{
							hienThongBao("Khong tim thay ma chuyen bay!");
						}
						else
						{
							break;
						}
					}
					while(true);
					
					int fix = hieuChinhCB(lstCB, p, lstMB);
					if (fix == 1)
					{
						hienThongBao("Hieu chinh thanh cong!");
						int save = saveCB(lstCB);
					}
					else
					{
						hienThongBao("Hieu chinh that bai!");
					}
					Normal();
					system("cls");
					break;
				}
				case soItem_MenuCB:
				{
					exit2 = 0;
					break;
				}
				}
			}
			break;
		}
		case soItem_MenuChinh:
		{
			return 0;
		}
			
		}
	}
	return 0;
}
