# Find & Replace in Multiple Files
grep -rl "exit(0)" . | xargs sed -i 's/exit(0)/exit(0)/g'
