# Security Policy

## Overview

The CSE 1201 - Object Oriented Programming Language repository is an educational resource containing code examples and learning materials. While this is primarily an educational repository, we take security seriously to ensure students learn secure coding practices.

## Scope

This security policy covers:

- Code examples in C++ and Java
- Build and CI/CD configurations
- Documentation and scripts
- Repository infrastructure

## Supported Versions

As an educational repository, we maintain:

| Version | Support Status |
| ------- | -------------- |
| Latest (main branch) | ✅ Actively maintained |
| Development branches | ⚠️ Experimental - may contain issues |
| Archived versions | ❌ No longer supported |

## Reporting a Vulnerability

If you discover a security vulnerability in this repository, please report it responsibly.

### What to Report

Please report issues including but not limited to:

- **Code vulnerabilities**: Buffer overflows, memory leaks, unsafe operations
- **Dependency vulnerabilities**: Issues in GitHub Actions or third-party tools
- **Configuration issues**: Insecure settings in CI/CD or build files
- **Documentation issues**: Instructions that could lead to security problems

### How to Report

**For security vulnerabilities, please do NOT create a public issue.**

Instead, please report privately through one of these methods:

1. **GitHub Security Advisories** (Preferred):
   - Go to the Security tab of this repository
   - Click "Report a vulnerability"
   - Fill out the advisory form

2. **Email**:
   - Contact the repository maintainers directly
   - Include "SECURITY" in the subject line
   - Provide detailed information about the vulnerability

### What to Include

When reporting a vulnerability, please include:

- **Description**: Clear description of the vulnerability
- **Location**: File path and line numbers
- **Impact**: Potential security impact
- **Steps to reproduce**: How to demonstrate the issue
- **Suggested fix**: If you have one (optional)
- **Your environment**: Compiler/JDK version, OS, etc.

### Response Timeline

- **Initial Response**: Within 48-72 hours
- **Status Update**: Within 1 week
- **Resolution**: Depends on severity and complexity

We will:
1. Confirm receipt of your report
2. Assess the vulnerability
3. Develop and test a fix
4. Release the fix and credit you (if desired)

## Security Best Practices for Contributors

When contributing to this repository, please follow these security guidelines:

### For C++ Code

- ✅ Use modern C++ standards (C++11 or later)
- ✅ Avoid raw pointers; prefer smart pointers
- ✅ Check array bounds
- ✅ Validate user input
- ✅ Handle exceptions properly
- ✅ Avoid buffer overflows
- ❌ Don't use unsafe functions (strcpy, gets, etc.)
- ❌ Don't ignore compiler warnings

### For Java Code

- ✅ Validate all inputs
- ✅ Use try-catch blocks appropriately
- ✅ Close resources properly (use try-with-resources)
- ✅ Avoid hardcoding sensitive information
- ✅ Use secure random number generators when needed
- ❌ Don't ignore exceptions
- ❌ Don't use deprecated or unsafe methods

### General Guidelines

- ✅ Keep dependencies updated
- ✅ Review code before committing
- ✅ Test code thoroughly
- ✅ Document security considerations
- ✅ Follow principle of least privilege
- ❌ Don't commit secrets, passwords, or API keys
- ❌ Don't use outdated or vulnerable libraries

## Educational Context

This repository is designed for learning. Some code examples may intentionally demonstrate:

- Common mistakes students make
- Vulnerabilities to avoid
- Before/after comparisons

Such examples should:
- Be clearly marked as "Bad Example" or "Insecure Example"
- Include explanations of why they're problematic
- Provide secure alternatives
- Not be used in production code

## Out of Scope

The following are generally out of scope for security reports:

- Theoretical vulnerabilities without proof of concept
- Issues in student-submitted homework or practice code
- Vulnerabilities in external textbooks or references
- General programming questions or suggestions

## Recognition

We appreciate security researchers and contributors who help keep this repository secure. If you report a valid security issue:

- We will acknowledge your contribution (with your permission)
- Your name will be added to our security hall of fame
- You can choose to remain anonymous

## Additional Resources

- [OWASP Top 10](https://owasp.org/www-project-top-ten/)
- [CWE Top 25 Most Dangerous Software Weaknesses](https://cwe.mitre.org/top25/)
- [CERT C++ Coding Standard](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682)
- [CERT Oracle Secure Coding Standard for Java](https://wiki.sei.cmu.edu/confluence/display/java/SEI+CERT+Oracle+Coding+Standard+for+Java)

## Contact

For security-related questions or concerns:

- Use GitHub Security Advisories (preferred)
- Open a private security issue
- Follow responsible disclosure practices

## Updates to This Policy

This security policy may be updated periodically. Check back regularly for the latest version.

---

**Last Updated**: November 2024

Thank you for helping keep CSE 1201 educational materials secure! 🔒
