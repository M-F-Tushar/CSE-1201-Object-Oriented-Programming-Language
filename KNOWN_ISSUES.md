# Known Issues and Future Improvements

This document tracks known issues, typos, and planned improvements for the repository.

## 📝 Naming Inconsistencies

### Folder Name Typo: "Leacture" vs "Lecture"

**Issue:** Some C++ lecture folders use "Leacture" instead of "Lecture"

**Affected Folders:**
- `OOP in C++/Leacture_01: An Overview of C++/`
- `OOP in C++/Leacture_02: Introducing Classes/`
- `OOP in C++/Leacture_03: A Closer Look at Classes/`
- `OOP in C++/Leacture_04: Arrays, Pointers, and References/`
- `OOP in C++/Leacture_05: Function Overloading/`
- `OOP in C++/Leacture_06: Introducing Operator Overloading/`

**Correctly Named Folders:**
- `OOP in C++/Lecture_07: Inheritance/`
- `OOP in C++/Lecture_08: Introducing the C++ IO System/`
- `OOP in C++/Lecture_09: Advanced C++ IO/`
- `OOP in C++/Lecture_10: Virtual Functions/`
- `OOP in C++/Lecture_11: Generic Functions/`
- `OOP in C++/Lecture_12: Run-Time Type Identification and the Casting Operators/`
- `OOP in C++/Lecture_13: Namespaces, Conversion Functions, and Miscellaneous Topics/`
- `OOP in C++/Lecture_14: Introducing the Standard Template Library/`

**Status:** Documented  
**Impact:** Low - Does not affect functionality  
**Workaround:** None needed - folders work as-is  

**Reason Not Fixed:** 
- Renaming would break existing bookmarks and external references
- Git history would show large changes
- All documentation has been updated to reflect current names
- Functionality is not impacted

**Future Consideration:** 
If there's a major repository restructuring in the future, this can be addressed. For now, all documentation (README, CONTENT_INDEX, GETTING_STARTED) uses the correct spelling in descriptions while maintaining actual folder names for accuracy.

---

## 🔄 Planned Improvements

### Documentation Enhancements
- [ ] Add visual diagrams for OOP concepts
- [ ] Create video tutorials for complex topics
- [ ] Add interactive examples

### Code Quality
- [ ] Add unit tests for example programs
- [ ] Implement code style linter configuration
- [ ] Add more comprehensive error handling examples

### Repository Features
- [ ] Create a GitHub Pages site for better browsing
- [ ] Add automated code quality checks
- [ ] Implement pull request templates
- [ ] Add issue templates for bug reports and feature requests

### Content Additions
- [ ] More real-world application examples
- [ ] Design pattern implementations
- [ ] Best practices guide
- [ ] Common pitfalls and how to avoid them

---

## 🐛 Bug Reports

No bugs currently reported. To report a bug:
1. Check this file to see if it's a known issue
2. Search existing GitHub issues
3. If not found, create a new issue with:
   - Description of the bug
   - Steps to reproduce
   - Expected vs actual behavior
   - System information (OS, compiler version, etc.)

---

## 💡 Feature Requests

To request a feature:
1. Check if it's already listed in "Planned Improvements"
2. Search existing GitHub issues
3. If not found, create a new issue with:
   - Clear description of the feature
   - Use case / motivation
   - Any implementation suggestions

---

## 🔍 Quality Assurance

### Current QA Status

✅ **Completed:**
- LICENSE file added (MIT)
- Contributing guidelines created
- Code of Conduct established
- Comprehensive documentation added
- GitHub Actions for CI/CD
- .editorconfig for consistent formatting
- Enhanced .gitignore

✅ **In Progress:**
- None currently

📋 **Backlog:**
- Full code compilation testing
- Documentation link validation
- Example output verification

---

## 📊 Statistics

Last Updated: November 2024

**Repository Health:**
- Documentation Coverage: Excellent (80+ guide files)
- Code Comments: Good (most files well-commented)
- Test Coverage: N/A (educational repository)
- CI/CD: Implemented (GitHub Actions)

---

## 📞 Contact

For questions about known issues or to report new ones:
- Open an issue on GitHub
- Follow the [Contributing Guidelines](CONTRIBUTING.md)
- Review the [Code of Conduct](CODE_OF_CONDUCT.md)

---

*This document is maintained by repository contributors and updated regularly.*
