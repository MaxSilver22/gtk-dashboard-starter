# gtk-dashboard-starter

This repository provides a **simple, modular template for a Linux desktop dashboard application using GTK (C)**. It is designed as a starting point for building modern, minimal dashboards on Debian-based systems.

**Status:** _In development — this template will evolve over time as features and best practices are refined._

## Features
- Fixed, full-height dark sidebar with minimal navigation buttons and logo
- Scrollable content area with multiple pages
- Modern flat dark theme using custom CSS and the Roboto font
- Modular C code structure for easy extension
- Aggressive in-code documentation and comments for learning and maintainability

## Included Packages, Libraries, and Resources
- **GTK+ 3**: Main GUI toolkit for windowing, widgets, and event handling
- **GLib**: Utility library for data types, signals, and main loop (used by GTK)
- **Pango**: Font and text rendering (used by GTK)
- **Roboto font**: Modern, readable font for UI (system or bundled)
- **Custom CSS**: For theming, layout, and button/sidebar/content styling
- **Logo image**: Example logo for sidebar branding
- **Makefile**: For building the application

## Project Structure
- `src/` — Modular C source files (main, dashboard window, sidebar, content area)
- `resources/` — CSS, fonts, and logo image
- `tests/` — Placeholder for future tests
- `.gitignore` — Ignores build artifacts and editor files

## Getting Started
1. Install dependencies: `sudo apt-get install build-essential pkg-config libgtk-3-dev fonts-roboto`
2. Build: `make`
3. Run: `./dashboard`

---

**License:**

This template is free for personal, educational, and non-commercial use. **Commercial use is strictly prohibited without explicit written permission from the author.** See the LICENSE file for details and contact information.

---

This template is intended as a **starting point** for your own Linux dashboard projects. Contributions and suggestions are welcome as the template evolves!
