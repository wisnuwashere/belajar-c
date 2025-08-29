#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 30
#define FILENAME "data_siswa.csv"

typedef struct
{
  char nis[20];
  char nama[MAX_NAME_LENGTH];
  char mata_pelajaran[MAX_SUBJECT_LENGTH];
  float nilai;
} Siswa;

Siswa students[MAX_STUDENTS];
int student_count = 0;

void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void toLowerCase(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower(str[i]);
  }
}

int isValidNIS(char *nis)
{
  if (strlen(nis) == 0)
    return 0;
  for (int i = 0; i < strlen(nis); i++)
  {
    if (!isdigit(nis[i]))
      return 0;
  }
  return 1;
}

int isValidName(char *nama)
{
  if (strlen(nama) == 0)
    return 0;
  for (int i = 0; i < strlen(nama); i++)
  {
    if (!isalpha(nama[i]) && nama[i] != ' ')
      return 0;
  }
  return 1;
}

int isValidGrade(float nilai)
{
  return (nilai >= 0 && nilai <= 100);
}

int searchStudentByNIS(char *nis)
{
  for (int i = 0; i < student_count; i++)
  {
    if (strcmp(students[i].nis, nis) == 0)
    {
      return i;
    }
  }
  return -1;
}

void sortByNIS()
{
  for (int i = 0; i < student_count - 1; i++)
  {
    for (int j = 0; j < student_count - i - 1; j++)
    {

      int nis1 = atoi(students[j].nis);
      int nis2 = atoi(students[j + 1].nis);

      if (nis1 > nis2)
      {
        Siswa temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

void sortByName()
{
  for (int i = 0; i < student_count - 1; i++)
  {
    for (int j = 0; j < student_count - i - 1; j++)
    {
      char nama1[MAX_NAME_LENGTH], nama2[MAX_NAME_LENGTH];
      strcpy(nama1, students[j].nama);
      strcpy(nama2, students[j + 1].nama);

      toLowerCase(nama1);
      toLowerCase(nama2);

      if (strcmp(nama1, nama2) > 0)
      {
        // Swap
        Siswa temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

void loadDataFromFile()
{
  FILE *file = fopen(FILENAME, "r");
  if (file == NULL)
  {
    printf("File %s tidak ditemukan. Memulai dengan data kosong.\n", FILENAME);
    return;
  }

  char line[200];
  student_count = 0;

  if (fgets(line, sizeof(line), file) != NULL)
  {

    if (strstr(line, "NIS") != NULL || strstr(line, "Nama") != NULL)
    {
    }
    else
    {

      rewind(file);
    }
  }

  while (fgets(line, sizeof(line), file) && student_count < MAX_STUDENTS)
  {

    line[strcspn(line, "\n")] = 0;

    char *token = strtok(line, ",");
    if (token != NULL)
    {
      strcpy(students[student_count].nis, token);

      token = strtok(NULL, ",");
      if (token != NULL)
      {
        strcpy(students[student_count].nama, token);

        token = strtok(NULL, ",");
        if (token != NULL)
        {
          strcpy(students[student_count].mata_pelajaran, token);

          token = strtok(NULL, ",");
          if (token != NULL)
          {
            students[student_count].nilai = atof(token);
            student_count++;
          }
        }
      }
    }
  }

  fclose(file);
  printf("Data berhasil dimuat dari file %s. Total %d siswa.\n", FILENAME, student_count);
}

// menyimpan data ke file CSV
void saveDataToFile()
{
  FILE *file = fopen(FILENAME, "w");
  if (file == NULL)
  {
    printf("Error: Tidak dapat membuka file %s untuk penulisan.\n", FILENAME);
    return;
  }

  // Write header
  fprintf(file, "NIS,Nama,Mata_Pelajaran,Nilai\n");

  // Write data
  for (int i = 0; i < student_count; i++)
  {
    fprintf(file, "%s,%s,%s,%.2f\n",
            students[i].nis,
            students[i].nama,
            students[i].mata_pelajaran,
            students[i].nilai);
  }

  fclose(file);
  printf("Data berhasil disimpan ke file %s\n", FILENAME);
}

// input data siswa baru
void inputStudent()
{
  if (student_count >= MAX_STUDENTS)
  {
    printf("Error: Database penuh! Maksimal %d siswa.\n", MAX_STUDENTS);
    return;
  }

  Siswa newStudent;

  printf("\n=== INPUT DATA SISWA ===\n");

  // Input dan validasi NIS
  do
  {
    printf("Masukkan NIS (hanya angka): ");
    scanf("%s", newStudent.nis);

    if (!isValidNIS(newStudent.nis))
    {
      printf("Error: NIS harus berupa angka saja!\n");
      continue;
    }

    if (searchStudentByNIS(newStudent.nis) != -1)
    {
      printf("Error: NIS %s sudah terdaftar!\n", newStudent.nis);
      continue;
    }

    break;
  } while (1);

  clearBuffer();

  // Input dan validasi nama
  do
  {
    printf("Masukkan Nama: ");
    fgets(newStudent.nama, sizeof(newStudent.nama), stdin);
    newStudent.nama[strcspn(newStudent.nama, "\n")] = 0; // Remove newline

    if (!isValidName(newStudent.nama))
    {
      printf("Error: Nama harus berupa huruf dan spasi saja!\n");
      continue;
    }
    break;
  } while (1);

  // Input mapel
  printf("Masukkan Mata Pelajaran: ");
  fgets(newStudent.mata_pelajaran, sizeof(newStudent.mata_pelajaran), stdin);
  newStudent.mata_pelajaran[strcspn(newStudent.mata_pelajaran, "\n")] = 0;

  // Input dan validasi
  do
  {
    printf("Masukkan Nilai (0-100): ");
    if (scanf("%f", &newStudent.nilai) != 1)
    {
      printf("Error: Input harus berupa angka!\n");
      clearBuffer();
      continue;
    }

    if (!isValidGrade(newStudent.nilai))
    {
      printf("Error: Nilai harus antara 0-100!\n");
      continue;
    }
    break;
  } while (1);

  // Tambahkan siswa ke array
  students[student_count] = newStudent;
  student_count++;

  printf("\nData siswa berhasil ditambahkan!\n");

  saveDataToFile();
}

// menampilkan semua data siswa dengan sorting
void displayAllStudents()
{
  if (student_count == 0)
  {
    printf("\nTidak ada data siswa.\n");
    return;
  }

  int choice;
  printf("\n=== TAMPILKAN DATA SISWA ===\n");
  printf("1. Urutkan berdasarkan NIS\n");
  printf("2. Urutkan berdasarkan Nama (Alfabetis)\n");
  printf("Pilih urutan (1-2): ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    sortByNIS();
    printf("\nData diurutkan berdasarkan NIS:\n");
    break;
  case 2:
    sortByName();
    printf("\nData diurutkan berdasarkan Nama (Alfabetis):\n");
    break;
  default:
    printf("\nPilihan tidak valid. Menampilkan data tanpa sorting:\n");
  }

  printf("\n%-10s %-20s %-15s %-8s\n", "NIS", "Nama", "Mata Pelajaran", "Nilai");
  printf("--------------------------------------------------------\n");

  for (int i = 0; i < student_count; i++)
  {
    printf("%-10s %-20s %-15s %-8.2f\n",
           students[i].nis,
           students[i].nama,
           students[i].mata_pelajaran,
           students[i].nilai);
  }
}

// detail siswa berdasarkan NIS
void displayStudentDetail()
{
  if (student_count == 0)
  {
    printf("\nTidak ada data siswa.\n");
    return;
  }

  char searchNIS[20];
  printf("\n=== CARI DETAIL SISWA ===\n");
  printf("Masukkan NIS siswa yang dicari: ");
  scanf("%s", searchNIS);

  int index = searchStudentByNIS(searchNIS);

  if (index == -1)
  {
    printf("Siswa dengan NIS %s tidak ditemukan.\n", searchNIS);
  }
  else
  {
    printf("\n=== DETAIL SISWA ===\n");
    printf("NIS            : %s\n", students[index].nis);
    printf("Nama           : %s\n", students[index].nama);
    printf("Mata Pelajaran : %s\n", students[index].mata_pelajaran);
    printf("Nilai          : %.2f\n", students[index].nilai);

    // Tambahan: Grade letter
    char grade;
    if (students[index].nilai >= 85)
      grade = 'A';
    else if (students[index].nilai >= 70)
      grade = 'B';
    else if (students[index].nilai >= 55)
      grade = 'C';
    else if (students[index].nilai >= 40)
      grade = 'D';
    else
      grade = 'E';

    printf("Grade          : %c\n", grade);
  }
}

// menu utama
void showMenu()
{
  printf("\n==================================\n");
  printf("    SISTEM DATA SISWA SEKOLAH     \n");
  printf("==================================\n");
  printf("1. Input Data Siswa\n");
  printf("2. Tampilkan Semua Data Siswa\n");
  printf("3. Cari Detail Siswa (berdasarkan NIS)\n");
  printf("4. Simpan Data ke File\n");
  printf("5. Muat Data dari File\n");
  printf("0. Keluar\n");
  printf("==================================\n");
  printf("Pilih menu (0-5): ");
}

// Fungsi utama program
int main()
{
  int choice;

  printf("Selamat datang di Sistem Data Siswa!\n");
  printf("Program ini akan membantu mengelola data siswa sekolah.\n");

  // Load data dari file saat program dimulai
  loadDataFromFile();

  do
  {
    showMenu();

    if (scanf("%d", &choice) != 1)
    {
      printf("Error: Input harus berupa angka!\n");
      clearBuffer();
      continue;
    }

    switch (choice)
    {
    case 1:
      inputStudent();
      break;
    case 2:
      displayAllStudents();
      break;
    case 3:
      displayStudentDetail();
      break;
    case 4:
      saveDataToFile();
      break;
    case 5:
      loadDataFromFile();
      break;
    case 0:
      printf("\nTerima kasih telah menggunakan program ini!\n");
      printf("Data akan otomatis tersimpan.\n");
      saveDataToFile(); // Auto-save sebelum keluar
      break;
    default:
      printf("Pilihan tidak valid! Silakan pilih 0-5.\n");
    }

    if (choice != 0)
    {
      printf("\nTekan Enter untuk melanjutkan...");
      clearBuffer();
      getchar();
    }

  } while (choice != 0);

  return 0;
}
