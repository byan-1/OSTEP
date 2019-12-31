1. 100%, one process will run 5 instructions after the another consecutively:
process 0   process 1   cpu   io
cpu         ready       1     
cpu         ready       1     
cpu         ready       1
cpu         ready       1
cpu         ready       1
done        cpu         1
done        cpu         1
done        cpu         1
done        cpu         1
done        cpu         1
done        done

2. 9 cycles to finish

process 0 process 1 cpu io
cpu       ready     1
cpu       ready     1
cpu       ready     1
cpu       ready     1
done      io-start  1
done      waiting       1
done      waiting       1
done      waiting       1
done      waiting       1
done      done      

3. Order matters as context is switched on io issue

process 0 process 1 cpu io
io-start  ready     1
waiting   cpu       1   1   
waiting   cpu       1   1
waiting   cpu       1   1
waiting   cpu       1   1
done      done

4.
process 0 process 1 cpu io
io-start  ready     1
waiting   waiting       1
waiting   waiting       1
waiting   waiting       1
waiting   waiting       1
done      cpu       1      
done      cpu       1   
done      cpu       1   
done      cpu       1   
done      done

5. Result will be same as (3) since context will switch once io begins

process 0 process 1 cpu io
io-start  ready     1
waiting   cpu       1   1   
waiting   cpu       1   1
waiting   cpu       1   1
waiting   cpu       1   1
done      done

6. system resources will not be utilized effectively; io will be waiting on processes to complete when they could be running

7. remaining io tasks will now be run in parallel when cpu is running.