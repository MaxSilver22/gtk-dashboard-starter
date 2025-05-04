// watcher.js
// Periodically checks the current directory for stack indicators and logs the detected stack.
const fs = require('fs');
const path = require('path');

const CHECK_INTERVAL_MS = 10000; // 10 seconds

function detectStack() {
  const files = fs.readdirSync(process.cwd());
  if (files.includes('package.json')) {
    return 'node';
  }
  if (files.includes('requirements.txt')) {
    return 'python';
  }
  if (files.includes('pyproject.toml')) {
    return 'python (poetry)';
  }
  if (files.includes('Gemfile')) {
    return 'ruby';
  }
  if (files.includes('go.mod')) {
    return 'go';
  }
  if (files.includes('Cargo.toml')) {
    return 'rust';
  }
  if (files.includes('composer.json')) {
    return 'php';
  }
  return 'unknown';
}

let lastStack = null;

function checkAndLogStack() {
  const stack = detectStack();
  if (stack !== lastStack) {
    console.log(`[watcher] Detected stack: ${stack}`);
    // Here you can add logic to trigger integration/matching
    lastStack = stack;
  }
}

console.log('[watcher] Starting stack watcher...');
checkAndLogStack();
setInterval(checkAndLogStack, CHECK_INTERVAL_MS); 