# Simple Linux Dashboard Template Using GTK

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

This template is intended as a **starting point** for your own Linux dashboard projects. Contributions and suggestions are welcome as the template evolves!

# Sequential Thinking MCP Server

An MCP server implementation that provides a tool for dynamic and reflective problem-solving through a structured thinking process.

## Features

- Break down complex problems into manageable steps
- Revise and refine thoughts as understanding deepens
- Branch into alternative paths of reasoning
- Adjust the total number of thoughts dynamically
- Generate and verify solution hypotheses

## Tool

### sequential_thinking

Facilitates a detailed, step-by-step thinking process for problem-solving and analysis.

**Inputs:**
- `thought` (string): The current thinking step
- `nextThoughtNeeded` (boolean): Whether another thought step is needed
- `thoughtNumber` (integer): Current thought number
- `totalThoughts` (integer): Estimated total thoughts needed
- `isRevision` (boolean, optional): Whether this revises previous thinking
- `revisesThought` (integer, optional): Which thought is being reconsidered
- `branchFromThought` (integer, optional): Branching point thought number
- `branchId` (string, optional): Branch identifier
- `needsMoreThoughts` (boolean, optional): If more thoughts are needed

## Usage

The Sequential Thinking tool is designed for:
- Breaking down complex problems into steps
- Planning and design with room for revision
- Analysis that might need course correction
- Problems where the full scope might not be clear initially
- Tasks that need to maintain context over multiple steps
- Situations where irrelevant information needs to be filtered out

## Configuration

### Usage with Claude Desktop

Add this to your `claude_desktop_config.json`:

#### npx

```json
{
  "mcpServers": {
    "sequential-thinking": {
      "command": "npx",
      "args": [
        "-y",
        "@modelcontextprotocol/server-sequential-thinking"
      ]
    }
  }
}
```

#### docker

```json
{
  "mcpServers": {
    "sequentialthinking": {
      "command": "docker",
      "args": [
        "run",
        "--rm",
        "-i",
        "mcp/sequentialthinking"
      ]
    }
  }
}
```

### Usage with VS Code

For quick installation, click one of the installation buttons below...

[![Install with NPX in VS Code](https://img.shields.io/badge/VS_Code-NPM-0098FF?style=flat-square&logo=visualstudiocode&logoColor=white)](https://insiders.vscode.dev/redirect/mcp/install?name=sequentialthinking&config=%7B%22command%22%3A%22npx%22%2C%22args%22%3A%5B%22-y%22%2C%22%40modelcontextprotocol%2Fserver-sequential-thinking%22%5D%7D) [![Install with NPX in VS Code Insiders](https://img.shields.io/badge/VS_Code_Insiders-NPM-24bfa5?style=flat-square&logo=visualstudiocode&logoColor=white)](https://insiders.vscode.dev/redirect/mcp/install?name=sequentialthinking&config=%7B%22command%22%3A%22npx%22%2C%22args%22%3A%5B%22-y%22%2C%22%40modelcontextprotocol%2Fserver-sequential-thinking%22%5D%7D&quality=insiders)

[![Install with Docker in VS Code](https://img.shields.io/badge/VS_Code-Docker-0098FF?style=flat-square&logo=visualstudiocode&logoColor=white)](https://insiders.vscode.dev/redirect/mcp/install?name=sequentialthinking&config=%7B%22command%22%3A%22docker%22%2C%22args%22%3A%5B%22run%22%2C%22--rm%22%2C%22-i%22%2C%22mcp%2Fsequentialthinking%22%5D%7D) [![Install with Docker in VS Code Insiders](https://img.shields.io/badge/VS_Code_Insiders-Docker-24bfa5?style=flat-square&logo=visualstudiocode&logoColor=white)](https://insiders.vscode.dev/redirect/mcp/install?name=sequentialthinking&config=%7B%22command%22%3A%22docker%22%2C%22args%22%3A%5B%22run%22%2C%22--rm%22%2C%22-i%22%2C%22mcp%2Fsequentialthinking%22%5D%7D&quality=insiders)

For manual installation, add the following JSON block to your User Settings (JSON) file in VS Code. You can do this by pressing `Ctrl + Shift + P` and typing `Preferences: Open Settings (JSON)`.

Optionally, you can add it to a file called `.vscode/mcp.json` in your workspace. This will allow you to share the configuration with others.

> Note that the `mcp` key is not needed in the `.vscode/mcp.json` file.

For NPX installation:

```json
{
  "mcp": {
    "servers": {
      "sequential-thinking": {
        "command": "npx",
        "args": [
          "-y",
          "@modelcontextprotocol/server-sequential-thinking"
        ]
      }
    }
  }
}
```

For Docker installation:

```json
{
  "mcp": {
    "servers": {
      "sequential-thinking": {
        "command": "docker",
        "args": [
          "run",
          "--rm",
          "-i",
          "mcp/sequentialthinking"
        ]
      }
    }
  }
}
```

## Building

Docker:

```bash
docker build -t mcp/sequentialthinking -f src/sequentialthinking/Dockerfile .
```

## License

This MCP server is licensed under the MIT License. This means you are free to use, modify, and distribute the software, subject to the terms and conditions of the MIT License. For more details, please see the LICENSE file in the project repository.

# GTK Dashboard Application (C, GTK3/4)

This project includes a modular, aggressively tested dashboard GUI application using GTK (C), inspired by Bootstrap 5's fixed sidebar layout. The application features:

- **Fixed, full-height dark sidebar** with minimal, padding-free buttons (Button1, Button2, ...)
- **Scrollable right content area** with pages (Page1, Page2, ...) corresponding to sidebar buttons
- **Modern flat dark theme** with Roboto font, light hover, and clear active state
- **Modular code structure**: each feature/component in its own C file
- **Aggressive testing**: both visual/manual and automated/unit tests

## Planned Directory Structure

- `src/` — Main application code
  - `main.c` — Entry point
  - `dashboard_window.c/.h` — Main window and layout
  - `sidebar.c/.h` — Sidebar widget
  - `content_area.c/.h` — Content area widget
  - `pages/` — Individual page modules (Page1, Page2, ...)
- `resources/`
  - `style.css` — Custom CSS for dark theme, Roboto font, hover/active effects
  - `fonts/Roboto/` — Roboto font files (or system font fallback)
- `tests/` — Automated and manual test scripts
- `Makefile` or `meson.build` — Build system

---

The application will be built up step by step, with each feature and module tested for both functionality and aesthetics before proceeding to the next stage.

---
