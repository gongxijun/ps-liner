使用ps-lite创建一个分布式dl网络来训练一个y = ax+b 方程.  
1. 目前支持的功能是： 1 同步的n worker 对 one server模式  
2. 主目录: trainliner.   
3. 说明： 为了给刚入门的人好阅读代码方便，这个demo没有进行任何模块封装.这样可以最直观的感受ps-lite
3.使用方式：

       启动scheduler
       1. liner ./bin/train_liner 2 1 scheduler
       10:59:35] /Users/rt/github/liner/ps-lite/src/van.cc:75: Bind to role=scheduler, id=1, ip=127.0.0.1, port=8000, is_recovery=0
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:236: assign rank=8 to node role=server, ip=10.222.68.202, port=50722, is_recovery=0
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:236: assign rank=9 to node role=worker, ip=10.222.68.202, port=50724, is_recovery=0
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:236: assign rank=11 to node role=worker, ip=10.222.68.202, port=50728, is_recovery=0
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:252: the scheduler is connected to 2 workers and 1 servers
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:292: Barrier count for 7 : 1
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:292: Barrier count for 7 : 2
       [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:292: Barrier count for 7 : 3
     2.启动server  
         liner ./bin/train_liner 2 1 server  

         启动Server
         [10:59:46] /Users/rt/github/liner/ps-lite/src/van.cc:75: Bind to role=server, ip=10.222.68.202, port=50722, is_recovery=0
         [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:282: S[8] is connected to others
         ps::sender : 11  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 9  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :9  grad_w : -1522.54  grad_b : -183.162 batich : 20  
         worker_id :11  grad_w : -2835.75  grad_b : -237.372 batich : 20  
         pull_w: 1.08957 pull_b: 0.105133
         pull_w: 1.08957 pull_b: 0.105133
         ps::sender : 9  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 11  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :11  grad_w : -2682.43  grad_b : -181.631 batich : 20  
         worker_id :9  grad_w : -2537.63  grad_b : -173.36 batich : 20  
         pull_w: 2.39458 pull_b: 0.193881
         pull_w: 2.39458 pull_b: 0.193881
         ps::sender : 9  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 11  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :11  grad_w : -16.0043  grad_b : -24.8863 batich : 20  
         worker_id :9  grad_w : -156.582  grad_b : -27.2976 batich : 20  
         pull_w: 2.43773 pull_b: 0.206927
         pull_w: 2.43773 pull_b: 0.206927
         ps::sender : 9  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 11  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :11  grad_w : 127.769  grad_b : -3.72871 batich : 20  
         worker_id :9  grad_w : -6.42502  grad_b : -19.7285 batich : 20  
         pull_w: 2.4074 pull_b: 0.212791
         pull_w: 2.4074 pull_b: 0.212791
         ps::sender : 11  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 9  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :9  grad_w : -58.8029  grad_b : -12.5737 batich : 20  
         worker_id :11  grad_w : -59.9953  grad_b : -21.5667 batich : 20  
         pull_w: 2.43709 pull_b: 0.221327
         pull_w: 2.43709 pull_b: 0.221327
         ps::sender : 9  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 11  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :11  grad_w : 32.0092  grad_b : -11.2871 batich : 20  
         worker_id :9  grad_w : 2.99533  grad_b : -13.6619 batich : 20  
         pull_w: 2.42834 pull_b: 0.227564
         pull_w: 2.42834 pull_b: 0.227564
         ps::sender : 11  merger_params: size = 1 ps::NumWorkers() : 2
         ps::sender : 9  merger_params: size = 2 ps::NumWorkers() : 2
         worker_id :9  grad_w : -41.6255  grad_b : -20.656 batich : 20  
         worker_id :11  grad_w : 83.0259  grad_b : 1.66902 batich : 20  
         pull_w: 2.41799 pull_b: 0.232311
         pull_w: 2.41799 pull_b: 0.232311

     3. 启动 worker
        ```markdown

```    
        liner ./bin/train_liner 2 1 worker 
        10:59:58] /Users/rt/github/liner/ps-lite/src/van.cc:75: Bind to role=worker, ip=10.222.68.202, port=50724, is_recovery=0
        [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:282: W[9] is connected to others
        启动Worker rank = 0
        ps
        worker_num    : 5
        server_num    : 2
        data
        file_type    : file
        file_path    : /Users/rt/github/liner/data
        file_pre    : liner_data
        divide_flag    : ,/
        pred_x: 7  pred_y: 0
        pred_x: 13  pred_y: 0
        pred_x: 10  pred_y: 0
        pred_x: 4  pred_y: 0
        pred_x: 3  pred_y: 0
        pred_x: 0  pred_y: 0
        pred_x: 12  pred_y: 0
        pred_x: 7  pred_y: 0
        pred_x: 7  pred_y: 0
        pred_x: 0  pred_y: 0
        
        worker_id  :0  w: 1.08957  b: 0.105133
        pred_x: 3  pred_y: 3.37385
        pred_x: 9  pred_y: 9.91127
        pred_x: 0  pred_y: 0.105133
        pred_x: 19  pred_y: 20.807
        pred_x: 16  pred_y: 17.5383
        pred_x: 17  pred_y: 18.6278
        pred_x: 12  pred_y: 13.18
        pred_x: 10  pred_y: 11.0008
        pred_x: 19  pred_y: 20.807
        pred_x: 19  pred_y: 20.807
        
        worker_id  :0  w: 2.39458  b: 0.193881
        pred_x: 7  pred_y: 16.956
        pred_x: 13  pred_y: 31.3235
        pred_x: 5  pred_y: 12.1668
        pred_x: 8  pred_y: 19.3506
        pred_x: 14  pred_y: 33.7181
        pred_x: 1  pred_y: 2.58847
        pred_x: 8  pred_y: 19.3506
        pred_x: 8  pred_y: 19.3506
        pred_x: 4  pred_y: 9.77222
        pred_x: 10  pred_y: 24.1397
        
        worker_id  :0  w: 2.43773  b: 0.206927
        pred_x: 2  pred_y: 5.08239
        pred_x: 9  pred_y: 22.1465
        pred_x: 1  pred_y: 2.64466
        pred_x: 17  pred_y: 41.6484
        pred_x: 8  pred_y: 19.7088
        pred_x: 18  pred_y: 44.0861
        pred_x: 15  pred_y: 36.7729
        pred_x: 5  pred_y: 12.3956
        pred_x: 3  pred_y: 7.52012
        pred_x: 5  pred_y: 12.3956
        
        worker_id  :0  w: 2.4074  b: 0.212791
        pred_x: 15  pred_y: 36.3237
        pred_x: 9  pred_y: 21.8793
        pred_x: 17  pred_y: 41.1385
        pred_x: 5  pred_y: 12.2498
        pred_x: 11  pred_y: 26.6941
        pred_x: 8  pred_y: 19.472
        pred_x: 5  pred_y: 12.2498
        pred_x: 12  pred_y: 29.1015
        pred_x: 16  pred_y: 38.7311
        pred_x: 18  pred_y: 43.5459
        
        worker_id  :0  w: 2.43709  b: 0.221327
        pred_x: 1  pred_y: 2.65842
        pred_x: 11  pred_y: 27.0294
        pred_x: 17  pred_y: 41.6519
        pred_x: 17  pred_y: 41.6519
        pred_x: 14  pred_y: 34.3407
        pred_x: 9  pred_y: 22.1552
        pred_x: 5  pred_y: 12.4068
        启动第二个worker
        liner ./bin/train_liner 2 1 worker
        [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:75: Bind to role=worker, ip=10.222.68.202, port=50728, is_recovery=0
        [11:00:08] /Users/rt/github/liner/ps-lite/src/van.cc:282: W[11] is connected to others
        启动Worker rank = 1
        ps
        worker_num    : 5
        server_num    : 2
        data
        file_type    : file
        file_path    : /Users/rt/github/liner/data
        file_pre    : liner_data
        divide_flag    : ,/
        pred_x: 7  pred_y: 0
        pred_x: 13  pred_y: 0
        pred_x: 9  pred_y: 0
        pred_x: 19  pred_y: 0
        pred_x: 5  pred_y: 0
        pred_x: 18  pred_y: 0
        pred_x: 0  pred_y: 0
        pred_x: 10  pred_y: 0
        pred_x: 6  pred_y: 0
        pred_x: 3  pred_y: 0
        
        worker_id  :1  w: 1.08957  b: 0.105133
        pred_x: 16  pred_y: 17.5383
        pred_x: 19  pred_y: 20.807
        pred_x: 7  pred_y: 7.73213
        pred_x: 19  pred_y: 20.807
        pred_x: 15  pred_y: 16.4487
        pred_x: 12  pred_y: 13.18
        pred_x: 9  pred_y: 9.91127
        pred_x: 14  pred_y: 15.3591
        pred_x: 19  pred_y: 20.807
        pred_x: 5  pred_y: 5.55299
        
        worker_id  :1  w: 2.39458  b: 0.193881
        pred_x: 1  pred_y: 2.58847
        pred_x: 19  pred_y: 45.691

           
            
       
# ps-liner
