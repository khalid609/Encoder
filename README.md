# 🔐 Encoder
 
A high-performance encoding utility built with C++ using Visual Studio.
 
---
 
## 📌 Description
 
**Encoder** is a C++ application designed to encode and process data efficiently. Built with Visual Studio 2022, it supports multiple build configurations including Debug and Release modes for both x86 and x64 platforms.
 
---
 
## 🚀 Features
 
- ⚡ Fast and lightweight encoding engine
- 🖥️ Cross-platform builds: x86 & x64
- 🛠️ Debug & Release configurations
- 📦 Clean Visual Studio solution structure
 
---
 
## 🏗️ Project Structure
 
```
Encoder/
├── Encoder.sln          # Visual Studio Solution file
├── Encoder/
│   ├── Encoder.vcxproj  # C++ Project file
│   ├── main.cpp         # Entry point
│   └── ...              # Source & header files
```
 
---
 
## 🔧 Requirements
 
- [Visual Studio 2022](https://visualstudio.microsoft.com/) or later
- C++ Desktop Development workload installed
- Windows OS (x86 or x64)
 
---
 
## 🛠️ Build Instructions
 
### Using Visual Studio GUI
 
1. Open `Encoder.sln` in Visual Studio
2. Select your desired configuration (`Debug` or `Release`) and platform (`x86` or `x64`)
3. Click **Build > Build Solution** (or press `Ctrl+Shift+B`)
4. The compiled output will be in `Debug/` or `Release/` folder
 
### Using Command Line (MSBuild)
 
```bash
msbuild Encoder.sln /p:Configuration=Release /p:Platform=x64
```
 
---
 
## ▶️ Usage
 
After building, run the executable from the output folder:
 
```bash
./x64/Release/Encoder.exe
```
 
---
 
## 📋 Build Configurations
 
| Configuration | Platform | Description              |
|---------------|----------|--------------------------|
| Debug         | x86      | 32-bit debug build       |
| Debug         | x64      | 64-bit debug build       |
| Release       | x86      | 32-bit optimized build   |
| Release       | x64      | 64-bit optimized build   |
 

 

 
---
 
## 📄 License
 
This project is licensed under the [MIT License](LICENSE).
 
---
 
## 👤 Author
 
**Khalid**
- GitHub: [@khalid609](https://github.com/khalid609)
 
---
 
> ⭐ If you find this project useful, please consider giving it a star!
