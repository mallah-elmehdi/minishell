
#!/bin/sh

# Credits: http://stackoverflow.com/a/750191

git filter-branch -f --env-filter "
    GIT_AUTHOR_NAME='mallah-elmehdi'
    GIT_AUTHOR_EMAIL='elmehdimallah@gmail.com'
    GIT_COMMITTER_NAME='mallah-elmehdi'
    GIT_COMMITTER_EMAIL='elmehdimallah@gmail.com'
  " HEAD
git push --force
