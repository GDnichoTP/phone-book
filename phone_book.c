#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

// batas maksimum
#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 50

// struktur data untuk menyimpan data kontak
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

// variabel global
Contact contacts[MAX_CONTACTS];  // array untuk menyimpan daftar kontak
int contact_count = 0;
int selected_index = 0;

// fungsi mengambar ui utama
void draw_ui(WINDOW *left, WINDOW *right, WINDOW *bottom) {
    // membersihkan isi setiap window
    werase(left);
    werase(right);
    werase(bottom);

    // menambahkan border pada setiap window
    box(left, 0, 0);
    box(right, 0, 0);
    box(bottom, 0, 0);

    // menambahkan judul pada setiap window
    mvwprintw(left, 0, 2, " Contacts ");
    mvwprintw(right, 0, 2, " Contact Details ");
    mvwprintw(bottom, 0, 2, " Shortcuts: [A]dd [E]dit [D]elete E[x]it ");

    // memperbaharui tampilan setiap window
    wrefresh(left);
    wrefresh(right);
    wrefresh(bottom);
}

// fungsi memperbaharui bagian kiri ui (daftar kontak)
void update_left(WINDOW *left) {
    werase(left);
    box(left, 0, 0);
    mvwprintw(left, 0, 2, " Contacts ");

    // menampilkan daftar kontak
    for (int i = 0; i < contact_count; i++) {
        if (i == selected_index) {
            wattron(left, A_REVERSE);  // highlight kontak yang dipilih
        }
        mvwprintw(left, i + 1, 2, "%s", contacts[i].name);
        wattroff(left, A_REVERSE);  // menghilangkan highlight
    }

    wrefresh(left);
}

// fungsi memperbaharui bagian kanan ui (data kontak)
void update_right(WINDOW *right) {
    werase(right);
    box(right, 0, 0);
    mvwprintw(right, 0, 2, " Contact Details ");

    // menampilkan data kontak
    if (contact_count > 0) {
        mvwprintw(right, 2, 2, "Name: %s", contacts[selected_index].name);
        mvwprintw(right, 3, 2, "Phone: %s", contacts[selected_index].phone);
        mvwprintw(right, 4, 2, "Email: %s", contacts[selected_index].email);
    } else {
        mvwprintw(right, 2, 2, "No contacts available.");  // jika daftar kosong
    }

    wrefresh(right);
}

// fungsi menerima input user
void get_user_input(const char *prompt, char *buffer, int buffer_size) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);  // mengambil ukuran layar terminal

    // membuat window di layar
    WINDOW *input_win = newwin(5, cols / 2, rows / 2 - 2, cols / 4);
    box(input_win, 0, 0);
    mvwprintw(input_win, 1, 2, "%s", prompt);  // menampilkan input yang diminta
    wrefresh(input_win);

    // mengaktifkan input teks
    echo();  // mengaktifkan echo
    curs_set(1);  // menampilkan cursor
    mvwgetnstr(input_win, 2, 2, buffer, buffer_size - 1);  // menerima input user

    // menghapus window
    delwin(input_win);
    noecho();  // menonaktifkan echo
    curs_set(0);  // menyembunyikan cursor
    clear();
}

// fungsi menambahkan kontak baru
void add_contact() {
    if (contact_count >= MAX_CONTACTS) {  // jika daftar penuh
        return;
    }

    // menerima input data kontak
    get_user_input("Enter Name: ", contacts[contact_count].name, MAX_NAME_LEN);
    get_user_input("Enter Phone: ", contacts[contact_count].phone, MAX_PHONE_LEN);
    get_user_input("Enter Email: ", contacts[contact_count].email, MAX_EMAIL_LEN);

    // menambah jumlah kontak
    contact_count++;
}

// fungsi mengubah data kontak
void edit_contact() {
    if (contact_count == 0) {  // jika daftar kosong
        return;
    }

    // menerima input data kontak yang baru
    get_user_input("Edit Name: ", contacts[selected_index].name, MAX_NAME_LEN);
    get_user_input("Edit Phone: ", contacts[selected_index].phone, MAX_PHONE_LEN);
    get_user_input("Edit Email: ", contacts[selected_index].email, MAX_EMAIL_LEN);
}

// fungsi menghapus kontak
void delete_contact() {
    if (contact_count == 0) {
        return;
    }

    // menggeser data kontak ke index setelahnya
    for (int i = selected_index; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--;  // mengurangi jumlah kontak

    // menyesuaikan index kontak yang dipilih jika kontak terakhir dihapus
    if (selected_index >= contact_count) {
        selected_index = contact_count - 1;
    }
}

// fungsi mengubah ukuran ui
void handle_resize(WINDOW **left, WINDOW **right, WINDOW **bottom) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);  // mengambil ukuran layar terminal terbaru

    // menghapus window lama
    delwin(*left);
    delwin(*right);
    delwin(*bottom);

    // membuat window baru 
    *left = newwin(rows - 3, cols / 2, 0, 0);
    *right = newwin(rows - 3, cols / 2, 0, cols / 2);
    *bottom = newwin(3, cols, rows - 3, 0);

    // menggambar ulang ui
    draw_ui(*left, *right, *bottom);
    update_left(*left);
    update_right(*right);
}

// fungsi utama
int main() {
    // inisiasi ncurses
    initscr();
    noecho();
    cbreak();  // menonaktifkan buffer
    curs_set(0);
    keypad(stdscr, TRUE);  // mengaktifkan input tombol khusus

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // membuat window
    WINDOW *left = newwin(rows - 3, cols / 2, 0, 0);
    WINDOW *right = newwin(rows - 3, cols / 2, 0, cols / 2);
    WINDOW *bottom = newwin(3, cols, rows - 3, 0);

    // menggambar ui awal
    draw_ui(left, right, bottom);
    update_left(left);
    update_right(right);

    // loop utama
    int ch;
    while ((ch = getch()) != 'x') {
        if (ch == KEY_RESIZE) {  // jika ukuran layar berganti
            handle_resize(&left, &right, &bottom);  // mengubah ukuran layar
        } else {
            switch (ch) {
                case 'A':
                case 'a':
                    add_contact();
                    break;
                case 'E':
                case 'e':
                    edit_contact();
                    break;
                case 'D':
                case 'd':
                    delete_contact();
                    break;

                // menyesuaikan index dari kontak yang dipilih
                case KEY_UP:
                    if (selected_index > 0) {
                        selected_index--;
                    }
                    break;
                case KEY_DOWN:
                    if (selected_index < contact_count - 1) {
                        selected_index++;
                    }
                    break;
            }

            // memperbaharui ui setiap menyelesaikan aksi
            draw_ui(left, right, bottom);
            update_left(left);
            update_right(right);
        }
    }

    // membersihkan terminal
    endwin();
    return 0;
}