# Find & Replace in Multiple Files
grep -rl "exitwait()" . | xargs sed -i 's/exitwait()/exitwait()/g'
