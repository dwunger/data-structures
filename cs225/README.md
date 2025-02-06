
# Add the remote upstream for the orphan repository WITHOUT lab solutions
git remote add cs225 https://github.com/dwunger/cs225.git

# Fetch branches from remote without merging them into working branch
git fetch cs225

# Add a specific branch to a specific path within the repository 
git subtree add --prefix=<subdir_path> <remote upstream name>/<branch name> --squash
- squash combines all commits from that branch into a single commit in your repository
# Example:
git subtree add --prefix=cs225/mp_lists cs225_remote/mp_lists --squash

# Fix the nesting of directories:
git mv mp_lists/mp_lists/* ./mp_lists/

## Optional:
# Return to last commit before you added the subtree:
# This will not remove untracked files
git reset HEAD~1
