<a name="readme-top"></a>

<div align="center">

## Phone Book Application 

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![WTFPL License][license-shield]][license-url]

</div>

<!-- PROJECT LOGO -->
</br>
<div align="center">
  <a href="https://www.unud.ac.id/">
    <img src="https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/ff71757a-1b51-44b7-b14e-b53b061d9815" alt="Logo" width="230" height="259">
  </a>

  <h3 align="center">Final Project: Algorithm Programming</h3>

  <p align="center">
    GUI based phone book application using C and Ncurses.
  </p>
</div>
</br>

<div align="center">
  
  ### Powered by:
  [![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black&style=for-the-badge)](https://www.python.org)
  [![Github][Github.com]][Github-url]

###
</div>
</br>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project-">About The Project</a></li>
    <li><a href="#building-the-project-">Building The Project</a></li>
    <li><a href="#license-">License</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project 📚
This project is created as a final project of my algorithm programming course in Udayana University. The main feature of this project is showcasing basic programming concepts in C, including struct, array, etc while applying ncurses as the GUI.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- BUILDING THE PROJECT -->
## Building The Project 🍳

### 1. Clone the Repository
```bash
git clone https://github.com/GDnichoTP/phone-book.git && cd phone-book
```

### 2. Install Dependencies
Ensure the following tools and libraries are installed on your system:

- **Windows**:
  1. Install `MinGW` or `Cygwin` to compile C programs.
  2. Download and install the `pdcurses` library, which is an ncurses alternative for Windows.
  3. Add `MinGW` or `Cygwin` to the system's PATH variable.
  
- **macOS**:
  Install `Xcode Command Line Tools`:
  ```bash
  xcode-select --install
  ```
  Then install ncurses via Homebrew if not already installed:
  ```bash
  brew install ncurses
  ```

- **Linux**:
  Ensure `gcc` and `ncurses` are installed:
  ```bash
  sudo apt-get install gcc libncurses5-dev libncursesw5-dev
  ```

### 3. Open the Project
You can run the project in these order:

#### Step 1: Compile the program

- **Linux/macOS**:
  ```bash
  gcc phone_book.c -o file_name -lncurses
  ```

- **Windows**:
  ```bash
  gcc phone_book.c -o file_name.exe -lpdcurses
  ```

#### Step 2: Run the project

- **Linux/macOS**:
  ```bash
  ./file_name
  ```
  
- **Windows**:
  ```bash
  file_name.exe
  ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License 📰

Distributed under the MIT License. See [`LICENSE`](./LICENSE) for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/GDnichoTP/phone-book?style=flat-square&color=%23ADD8E6
[contributors-url]: https://github.com/GDnichoTP/phone-book/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/GDnichoTP/phone-book?style=flat-square&color=%23ADD8E6
[forks-url]: https://github.com/GDnichoTP/phone-book/forks
[license-shield]: https://img.shields.io/github/license/GDnichoTP/phone-book?style=flat-square&color=%23ADD8E6
[license-url]: https://github.com/GDnichoTP/phone-book/blob/main/LICENSE
[Github.com]: https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge&logo=GitHub&logoColor=white
[Github-url]: https://github.com/
