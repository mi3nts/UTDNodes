# UTDNodes
## crontab Input
```
  GNU nano 2.5.3                      File: /tmp/crontab.S1HL7e/crontab                                                    

# Edit this file to introduce tasks to be run by cron.
#
# Each task to run has to be defined through a single line
# indicating with different fields when the task will be run
# and what command to run for the task
#
# To define the time you can provide concrete values for
# minute (m), hour (h), day of month (dom), month (mon),
# and day of week (dow) or use '*' in these fields (for 'any').#
# Notice that tasks will be started based on the cron's system
# daemon's notion of time and timezones.
#
# Output of the crontab jobs (including errors) is sent through
# email to the user the crontab file belongs to (unless redirected).
#
# For example, you can run a backup of all your user accounts
# at 5 a.m every week with:
# 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
#
# For more information see the manual pages of crontab(5) and cron(8)
#
## m h  dom mon dow   command
@reboot cd /home/teamlary/gitHubRepos/Lakitha/UTDNodes/firmware/xu4 && ./runAll.sh
*/1 * * * * rsync -avzrtu -e "ssh -p 2222" /home/teamlary/mintsData/raw/ mints@mintsdata.utdallas.edu:raw/
*/10 * * * * cd /home/teamlary/gitHubRepos/Lakitha/UTDNodes/firmware/xu4 && python3 skyCamReaderWithSave.py
2,4,6,8,12,14,16,18,22,24,26,28,32,34,36,38,42,44,46,48,52,54,56,58 * * * * cd /home/teamlary/gitHubRepos/Lakitha/UTDNodes$
*/1 * * * * cd /home/teamlary/gitHubRepos/Lakitha/UTDNodes/firmware/xu4 && python3 deleter.py
```




