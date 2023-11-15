# CRON-JOBS:
```crontab -e``` <br>
This command opens the CRON-EDITOR in which we need to add the specific date-time-path

```man cron```<br>
```man crontab```<br>
These commands will help into knowning the basic format for writing into the CRON-EDITOR and how the CRON-JOB works

# NEW-USER:
```sudo useradd (username)```<br>
This command help to add a new username to my system with privileges less than or equal to mine(root)

```sudo userdel -r (username)```<br>
This command helps to delete all the details from my /etc/passwd file and also deletes the directory from /home

```rm -rf (username)```<br>
[Note: when using userdel (-r) flag is neccesary and without which, we may need to remove the /home/(username)]<br>

# GROUPS: