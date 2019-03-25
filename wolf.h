#ifndef WOLF_H
# define WOLF_H

typedef struct s_hero
{
    int x;
    int y;
}               t_hero;

typedef struct      s_bmpheader
{
    unsigned char	b1,b2;			//Символы BM (смение 0, длина 2)
	unsigned short	bfSize;			//Размер файла в байтах	(Смещение 2, длина 2)
	unsigned short	bfReserved1;	        //Бесполезно (Смещение 6, длина 2)
	unsigned short	bfReserved2;	        //Бесполезно (Смещение 8, длина 2)
	unsigned short  padding;		//Мусор, для выравнивания
	unsigned short	bfOffBits;		//Смещение до самого изображения (Смещение 10, длина 2)
    char            a[42];
}           t_bmphead;

typedef struct s_data
{
    char data[1900*1200*3];
}               t_data;
#endif