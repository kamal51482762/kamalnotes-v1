

git hub password:

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


Error:



sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ git push -u origin main
Username for 'https://github.com': kamal51482762
Password for 'https://kamal51482762@github.com': 
To https://github.com/kamal51482762/kamalnotes-v1.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/kamal51482762/kamalnotes-v1.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 


Solution

sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ git pull origin main --rebase


Yahan par remote mera origin hai 

and mera branch hai main ok ..


git pull origin main --rebase  karne ke baad main branch mein koi v chnages hua hai toh tumko wah chnages ajaenge ok ...
iske baad koi v admi kuch files ko add kiya hai or koi chnages kiya hai toh tumhara directory mein wah chnages ajayenge ok ...


sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ ls
hello.txt  platform
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 


git push command :

sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ git push -u origin main
Username for 'https://github.com': kamal51482762
Password for 'https://kamal51482762@github.com': 
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 338 bytes | 338.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/kamal51482762/kamalnotes-v1.git
   d576599..fc1f223  main -> main
Branch 'main' set up to track remote branch 'main' from 'origin'.
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 
sumiama@sumiama-Vostro-15-3568:~/Desktop/kamalnotes-v1$ 



NOTE:




