# Changelog

All notable changes to this repository will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned
- Visual diagrams for OOP concepts
- Video tutorials for complex topics
- GitHub Pages site for better browsing
- Pull request and issue templates
- More real-world application examples

## [2.0.0] - 2024-11-02

### Added - Major Repository Improvements

#### Documentation
- **LICENSE** - MIT License for open educational use
- **CONTRIBUTING.md** - Comprehensive contribution guidelines for students and educators
- **CODE_OF_CONDUCT.md** - Community standards and academic integrity guidelines
- **GETTING_STARTED.md** - Complete beginner's guide with setup instructions
- **CONTENT_INDEX.md** - Comprehensive catalog of all 156+ programs and 80+ documentation files
- **KNOWN_ISSUES.md** - Tracking of known issues and future improvements
- **CHANGELOG.md** - This file, tracking all repository changes

#### Enhanced README.md
- Added repository badges (License, Stars, Forks, PRs Welcome)
- Created comprehensive table of contents
- Added detailed repository structure diagram
- Included setup instructions for C++ and Java
- Added running instructions with examples
- Expanded learning objectives section
- Added repository statistics (139 C++ programs, 17 Java programs, 80+ docs)
- Improved formatting and visual appeal

#### Development Tools
- **.editorconfig** - Consistent code formatting across editors
  - 4-space indentation for C++ and Java
  - UTF-8 encoding
  - LF line endings
  - Trim trailing whitespace
  
- **.gitignore** - Enhanced with comprehensive ignore patterns
  - C++ compiled files (*.o, *.exe, *.out, *.a, *.so, *.dll)
  - Java compiled files (*.class, *.jar)
  - IDE files (VS Code, IntelliJ, Eclipse, NetBeans)
  - OS files (macOS, Windows, Linux)
  - Build directories
  - Temporary files

#### CI/CD - GitHub Actions Workflows
- **cpp-build.yml** - Automated C++ compilation checking
  - Runs on push/PR to main and develop branches
  - Compiles all C++ files with g++
  - Uses C++17 standard
  - Reports compilation errors
  
- **java-build.yml** - Automated Java compilation checking
  - Runs on push/PR to main and develop branches
  - Compiles all Java files with JDK 17
  - Reports compilation errors
  
- **markdown-check.yml** - Markdown link validation
  - Checks all markdown files for broken links
  - Configurable retry logic
  - Helps maintain documentation quality

#### Repository Structure
- Organized GitHub workflows in `.github/workflows/`
- Added markdown link check configuration

### Changed
- README.md significantly enhanced with better structure and information
- .gitignore expanded from 33 to 150+ lines with comprehensive patterns

### Documentation Improvements
- All major sections now have detailed guides
- Cross-references added between related topics
- Learning paths suggested for different skill levels
- Quick reference sections added
- Better navigation with table of contents

### Quality Improvements
- Automated testing for code compilation
- Consistent code formatting standards
- Clear contribution guidelines
- Community standards established
- Academic integrity policies documented

## [1.0.0] - Prior to 2024-11-02

### Existing Content
- 139 C++ program files across 14 lectures
- 17 Java program files across 13 chapters
- 80+ markdown documentation files
- Comprehensive examples for all OOP concepts
- Practice problems and exercises
- Exam materials (CT, Lab, Final)

#### C++ Content (Lectures 1-14)
- Overview of C++
- Classes and Objects
- Constructors and Destructors
- Arrays, Pointers, and References
- Function Overloading
- Operator Overloading
- Inheritance
- I/O Systems
- Virtual Functions and Polymorphism
- Templates and Generic Programming
- Exception Handling
- RTTI and Casting
- Namespaces and Conversion Functions
- Standard Template Library (STL)

#### Java Content (Chapters 1-13)
- Introduction to Java
- Elementary Programming
- Control Structures
- Methods and Arrays
- Objects and Classes
- Object-Oriented Thinking
- Inheritance and Polymorphism
- Exception Handling
- Abstract Classes and Interfaces

#### Documentation
- Detailed README files for most chapters
- Code examples with comments
- Topic-specific markdown guides
- Practice exercises

## Version Numbering

This repository uses semantic versioning:
- MAJOR version: Significant restructuring or major content additions
- MINOR version: New lectures, chapters, or significant documentation
- PATCH version: Bug fixes, minor documentation updates

---

## How to Contribute to the Changelog

When making changes, please update this changelog with:
- Date of change
- Category (Added/Changed/Deprecated/Removed/Fixed/Security)
- Description of the change
- Any relevant details or breaking changes

See [CONTRIBUTING.md](CONTRIBUTING.md) for full contribution guidelines.

---

## Links

- [Repository](https://github.com/M-F-Tushar/CSE-1201-Object-Oriented-Programming-Language)
- [Contributing Guidelines](CONTRIBUTING.md)
- [Code of Conduct](CODE_OF_CONDUCT.md)
- [License](LICENSE)

---

*This changelog is maintained according to [Keep a Changelog](https://keepachangelog.com/) principles.*
