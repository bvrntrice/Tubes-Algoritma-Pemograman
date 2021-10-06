#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void total(int Pajak, int Harga) // prosedur
{
    int Total;
    Total=Pajak+Harga;
    printf("\nTotal Harga     : Rp.%d", Total);

}
void userlogin(void);

struct user{
    char username[10];
    char password[10];
}*pUser;

int menu_kopi()
{
 printf("\n====== PERMATA COFFEE SHOP ======\n\n");
        printf("Menu : ");
        printf("\n    1. Latte");
        printf("\n    2. Expresso");
        printf("\n    3. Americano");
        printf("\n    4. Vietnam Drip");

}
int main()
{
    userlogin() ;

    FILE*data;

    int harga, i, tot;
    float pajak;
    char ulangi, nama[20], telp[20][20];


    struct cuci{ //struct
        char plus;
        int jenis;
        int sabun;
        }cuci;

    printf("\n====== SALON MOBIL PERMATA ======\n\n");
    printf("Pilih Jenis Cuci  :");
    printf("\n                  1.Salon Mesin");
    printf("\n                  2.Eksterior");
    printf("\n                  3.Interior");
    printf("\n                  4.Eksterior & Interior");
    printf("\n                  5.Komplit Luar Dalam");
    printf("\nPilihan : ");
    scanf("%d", &cuci.jenis);

    switch (cuci.jenis){ //switch case
        case 1 : cuci.jenis=50000 ;break;
        case 2 : cuci.jenis=60000 ;break;
        case 3 : cuci.jenis=75000 ;break;
        case 4 : cuci.jenis=120000 ;break;
        case 5 : cuci.jenis=2000000 ;break;
    }
    system("cls"); //cls
    printf("\n====== SALON MOBIL PERMATA ======\n\n");
    printf("Pilih Jenis Sabun :");
    printf("\n                  1.Reguler");
    printf("\n                  2.Premium");
    printf("\n                  3.Super");
    printf("\nPilihan : ");
    scanf("%d", &cuci.sabun);

    switch (cuci.sabun){
        case 1 : cuci.sabun=50000 ;break;
        case 2 : cuci.sabun=60000 ;break;
        case 3 : cuci.sabun=75000 ;break;
    }

    system("cls");
    printf("\n====== SALON MOBIL PERMATA ======\n\n");
    fflush(stdin);
    printf("Plus Detailing ? (Y/N) : ");
    scanf("%c", &cuci.plus);


    fflush(stdin);

    do{ // do while
        fflush(stdin);
        printf("\nMasukan Nama : ");
        fgets(nama,20,stdin);
        printf("Nama Sudah Benar ? [Y/N]");
        scanf("%s", &ulangi);
    }while ((ulangi=='N') || (ulangi=='n'));

    for(i=1; i<3; i++){
        printf("Masukan No telp %d : ", i);
        fflush(stdin);
        fgets(telp[i],20,stdin);
    }

    system("cls");
    printf("\n====== SALON MOBIL PERMATA ======\n\n");
    printf("\nAtas Nama       : %s", nama);

    for(i=1; i<3; i++){ //for
        printf("Nomor telepon %d : %s",i ,telp[i]);
    }


    printf("Harga Salon     : Rp.%d", cuci.jenis);
    printf("\nHarga Sabun     : Rp.%d", cuci.sabun);

    if ( (cuci.plus=='y') || (cuci.plus=='Y') ){ //if else
        printf("\nDetailing       : Rp.1000000");
        harga=cuci.jenis+cuci.sabun+1000000;
    }
    else{
        harga=cuci.jenis+cuci.sabun;
    }
    float *pa;
    *pa=0.10;
    pajak=harga*(*pa);
    printf("\nPajak           : Rp.%2.f", pajak);
    total(pajak, harga);

    data=fopen("data.txt", "a"); //operasi file
    fprintf(data,"\n\n%s Harga : %d Pajak : %2.f", nama, harga, pajak );
    fclose(data);

    FILE*datakopi;
    char menu, kopi[20][20], cari[20];
    int n, j, hc[20], hargaa[20], tk=0;
    printf("\n\nIngin Pesan Kopi ? (Y/N)");
    scanf("%c", &menu);
    if((menu=='y')||(menu=='Y')){
    system("cls");

        menu_kopi();

        printf("\n\nJumlah pesanan : ");
        scanf("%d", &n);
        for(j=1; j<=n ; j++){
            printf("\n\nMasukan Pesanan ke %d: ", j);
            fflush(stdin);
            fgets(kopi[j],20,stdin);
            printf("\n(1)Hot or (2)Cold : ");
            scanf("%d", &hc[j]);
            if(hc[j]==2){
                hargaa[j]=20000+5000;

            }
            else{
                hargaa[j]=20000;
            }
            printf("Harga : Rp.%d", hargaa[j]);
            }

        }

    else{
        printf("TERIMAKASIH");}

    for(j=1;j<=n;j++){
        tk=tk+hargaa[j];
    }

        for(int i=0;i<3;i++){

            int j,bd;
            j=i;
            //selesction sort
            for(int k=i+1;k<3;k++)
            {
                    bd=strcmp(kopi[j],kopi[k]);
                    if(bd==1) j=k;        // angka 1 merupakan urut data secara ascending, untuk descending ganti dengan -1
                    }
                                if(j!=i){
                             char temp[1][30]; // Swapping
                             strcpy(temp[0],kopi[j]);
                             strcpy(kopi[j],kopi[i]);
                             strcpy(kopi[i],temp[0]);}
                    }
    system("cls");
    printf("\nPesanan Anda : ");
    for (int i=0;i<=n;i++){ // Menampilkan hasil
        printf("\n%s", kopi[i]);
        }
    printf("\n\nTotal : Rp.%d\n\n",tk);

    datakopi=fopen("datakopi.txt", "a"); //operasi file
    fprintf(datakopi,"\n\n%s Total Harga : %d", nama, tk );
    fclose(data);



}
void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10];int i;char c;

    pUser=(struct user *)malloc(sizeof(struct user));

    printf("1. Login Through An Existing Account\n2. Create New account\n");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",uName);
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        //accessUser();
                    }
                }
            }
            break;

        case 2:
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
    }
    free ( pUser);//free allocated memory
    fclose(fp);
}


