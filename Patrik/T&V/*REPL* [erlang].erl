Eshell V5.10.2  (abort with ^G)
1> pwd().
/Users/origooo/Dropbox/TERM4/Term4GIT/Term4-C_collaboration/Patrik/T&V
ok
2> c(assignment5).
assignment5.erl:17: syntax error before: '->'
error
3> c(assignment5).
assignment5.erl:21: Warning: variable 'List2' is unused
{ok,assignment5}
4> From = 1.
1
5> To = 20.
20
6> Incr = 1.
1
7> Incr2 = 2.
2
8> List = lists:seq(From,To,Incr).
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
9> List2 = [X || [X,Y|[]] <- List, X = Y - Incr]
.
[]
10> f(List2).
ok
11> List2 = [X || [X,Y|[]] <- List && X = Y - Incr]
.
* 1: syntax error before: '&'
11> f(List2).
ok
12> List2 = [X || [X,Y|[]] <- List & X = Y - Incr].
* 1: syntax error before: '&'
12> List2 = [X || [X,Y|[]] <- List, X = Y - Incr].
[]
13> c(assignment5).
{ok,assignment5}
14> eqc:quickcheck(assignment5:prop_seq3_Incr()).
** exception error: undefined function assignment5:prop_seq3_Incr/0
15> c(assignment5).
{ok,assignment5}
16> eqc:quickcheck(assignment5:prop_seq3_Incr()).
Starting eqc mini version 1.0.1 (compiled at {{2010,6,13},{11,15,30}})
...Failed! After 4 tests.
{-1,1,0}
Shrinking.(1 times)
{0,1,0}
false
17> c(assignment5).
{ok,assignment5}
18> c(assignment5).
{ok,assignment5}
19> eqc:quickcheck(assignment5:prop_seq3_Incr()).
xxxxxxxxxx..xxxxxFailed! After 3 tests.
{0,-1,-1}
Shrinking.(1 times)
{0,1,-1}
false
20> c(assignment5).
{ok,assignment5}
21> eqc:quickcheck(assignment5:prop_seq3_Incr()).
xxxxxxxxxx...x..Failed! After 6 tests.
{-1,-2,-1}
Shrinking...(3 times)
{0,1,-1}
false
22> c(assignment5).
{ok,assignment5}
23> eqc:quickcheck(assignment5:prop_seq3_Incr()).
......Failed! After 7 tests.
{-1,1,0}
Shrinking.(1 times)
{0,1,0}
false
24> c(assignment5).
{ok,assignment5}
25> eqc:quickcheck(assignment5:prop_seq3_Incr()).
xxxxxxxxxxFailed! After 1 tests.
{1,-1,-1}
Shrinking..(2 times)
{0,1,-1}
false
26> List.
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
27> ListT = [X || [X|Y] <- List, X = hd(Y) - Incr].
[]
28> f(ListT).
ok
29> ListT = [X || X <- List, X = hd(tl(List)) - Incr].
** exception error: bad filter 1
30> ListT = [X || [X] <- List, X = hd(tl(List)) - Incr].
[]
31> f(ListT).
ok
32> ListT = [X || [X] <- List].
[]
33> f(ListT).
ok
34> ListT = [X || X <- List].
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
35> f(ListT).
ok
36> 
.
* 2: syntax error before: '.'
36> ListT = [X || [X] <- List, (X = hd(tl(List)) - Incr)].
[]
37> f(ListT).
ok
38> ListT = [X || X <- List, (X = hd(tl(List)) - Incr)].
** exception error: bad filter 1
39> ListT = [X || X <- List, X = (hd(tl(List)) - Incr)].
** exception error: bad filter 1
40> ListT = [X || [X|Y] <- List, X == Y - Incr or Y == []].
* 1: syntax error before: '=='
40> ListT = [X || [X|Y] <- List, (X == Y - Incr) or (Y == [])].
[]
41> f(ListT).
ok
42> c(assignment5).
{ok,assignment5}
43> eqc:quickcheck(assignment5:prop_seq3_Incr()).
Starting eqc mini version 1.0.1 (compiled at {{2010,6,13},{11,15,30}})
xxxxxxxxxxxxxxxxFailed! After 1 tests.
{1,0,-1}
false
44> c(assignment5).
{ok,assignment5}
45> c(assignment5).
{ok,assignment5}
46> assignment5:test_gen().
{{eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>}}
47> c(assignment5).
{ok,assignment5}
48> assignment5:test_gen().
{{eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>}}
49> c(assignment5).
assignment5.erl:29: Warning: variable 'One' is unused
assignment5.erl:29: Warning: variable 'Three' is unused
assignment5.erl:29: Warning: variable 'Two' is unused
{ok,assignment5}
50> assignment5:test_gen().
{{eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>},
 {eqc_gen,#Fun<eqc_gen.9.9438484>}}
51> i().
Pid                   Initial Call                          Heap     Reds Msgs
Registered            Current Function                     Stack              
<0.0.0>               otp_ring0:start/2                      987     3922    0
init                  init:loop/1                              2              
<0.3.0>               erlang:apply/2                        4185   954676    0
erl_prim_loader       erl_prim_loader:loop/3                   6              
<0.6.0>               gen_event:init_it/6                    987      355    0
error_logger          gen_event:fetch_msg/5                    9              
<0.7.0>               erlang:apply/2                        6772    12394    0
application_controlle gen_server:loop/6                        7              
<0.9.0>               application_master:init/4              376       44    0
                      application_master:main_loop/2           6              
<0.10.0>              application_master:start_it/4          233       69    0
                      application_master:loop_it/4             5              
<0.11.0>              supervisor:kernel/1                   6772    41254    0
kernel_sup            gen_server:loop/6                        9              
<0.12.0>              rpc:init/1                             233       35    0
rex                   gen_server:loop/6                        9              
<0.13.0>              global:init/1                          233       50    0
global_name_server    gen_server:loop/6                        9              
<0.14.0>              erlang:apply/2                         233       20    0
                      global:loop_the_locker/1                 5              
<0.15.0>              erlang:apply/2                         233        3    0
                      global:loop_the_registrar/0              2              
<0.16.0>              inet_db:init/1                         233      273    0
inet_db               gen_server:loop/6                        9              
<0.17.0>              global_group:init/1                    233       59    0
global_group          gen_server:loop/6                        9              
<0.18.0>              file_server:init/1                     610    14164    0
file_server_2         gen_server:loop/6                        9              
<0.19.0>              erlang:apply/2                        4185   267663    0
code_server           code_server:loop/1                       3              
<0.20.0>              supervisor_bridge:standard_error/      233       41    0
standard_error_sup    gen_server:loop/6                        9              
<0.21.0>              erlang:apply/2                         233        9    0
standard_error        standard_error:server_loop/1             2              
<0.22.0>              supervisor_bridge:user_sup/1           233       64    0
                      gen_server:loop/6                        9              
<0.24.0>              erlang:apply/2                         610    52207    0
user                  user:server_loop/2                       9              
<0.25.0>              erlang:apply/2                        6772    12467    0
                      shell:shell_rep/4                       17              
<0.26.0>              kernel_config:init/1                   233      286    0
                      gen_server:loop/6                        9              
<0.27.0>              supervisor:kernel/1                    233       58    0
kernel_safe_sup       gen_server:loop/6                        9              
<0.91.0>              application_master:init/4              376       42    0
                      application_master:main_loop/2           6              
<0.92.0>              application_master:start_it/4          233       49    0
                      application_master:loop_it/4             5              
<0.93.0>              supervisor:inets_sup/1                 233      307    0
inets_sup             gen_server:loop/6                        9              
<0.94.0>              supervisor:ftp_sup/1                   233       52    0
ftp_sup               gen_server:loop/6                        9              
<0.95.0>              supervisor:httpc_sup/1                 233      171    0
httpc_sup             gen_server:loop/6                        9              
<0.96.0>              supervisor:httpc_profile_sup/1         233      122    0
httpc_profile_sup     gen_server:loop/6                        9              
<0.97.0>              httpc_manager:init/1                   233       78    0
httpc_manager         gen_server:loop/6                        9              
<0.98.0>              supervisor:httpc_handler_sup/1         233       52    0
httpc_handler_sup     gen_server:loop/6                        9              
<0.99.0>              supervisor:httpd_sup/1                 233       43    0
httpd_sup             gen_server:loop/6                        9              
<0.100.0>             supervisor:tftp_sup/1                  233       52    0
tftp_sup              gen_server:loop/6                        9              
<0.197.0>             erlang:apply/2                        2586    32250    0
                      c:pinfo/1                               50              
<0.215.0>             erlang:apply/2                         233     2428    0
eqcmini               eqc:f506_0/2                             3              
<0.216.0>             erlang:apply/2                         233       11    0
eqcmini_logger        eqc:f1616_0/1                            2              
Total                                                      40577  1395770    0
                                                             301              
ok
52> c(assignment5).
assignment5.erl:29: Warning: variable 'One' is unused
assignment5.erl:29: Warning: variable 'Three' is unused
assignment5.erl:29: Warning: variable 'Two' is unused
{ok,assignment5}
53> c(assignment5).
{ok,assignment5}
54> eqc:quickcheck(assignment5:prop_seq3_Incr()).
xxxxxxxxxx..xxxx.Failed! After 4 tests.
{-1,-2,-1}
Shrinking...(3 times)
{0,1,-1}
false
55> ListT = [X || [X|Y] <- List, (X == Y - Incr) or (Y == [])].
[]
56> f(ListT).
ok
57> List.
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
58> f(ListT).
ok
59> ListT = [X || [X|Y] <- List, (Y == X + Incr) or (Y == [])].
[]
60> f(ListT).
ok
61> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) or (Y == [])].
[]
62> f(ListT).
ok
63> ListT = [X || [X|Y] <- List, (Y == [])].
[]
64> f(ListT).
ok
65> ListT = [X || [X|Y] <- List, (Y = [])].
[]
66> f(ListT).
ok
67> ListT = [X || [X|[Y]] <- List, (hd(Y) == X + Incr) or (Y == [])].
[]
68> f(ListT).
ok
69> ListT = [X | [X|Y] <- List, (hd(Y) == X + Incr) or (Y == [])].
* 1: syntax error before: '<-'
69> ListT = [X || [X|[Y]] <- List, (hd(Y) == X + Incr) or (Y == [])].
[]
70> f(ListT).
ok
71> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) or (Y == [])].
[]
72> f(ListT).
ok
73> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) or (hd(Y) == [])].
[]
74> f(ListT).
ok
75> List.
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
76> ListT = [X || [X|Y] <- List, (Y /= [] and hd(Y) == X + Incr) or (Y == [])].
* 1: syntax error before: '=='
76> ListT = [X || [X|Y] <- List, ((Y /= []) and (hd(Y) == X + Incr)) or (Y == [])].
[]
77> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
78> f(ListT).
ok
79> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
80> List.
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
81> f(ListT).
ok
82> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
83> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
84> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
85> ListT = [1].
** exception error: no match of right hand side value [1]
86> f(ListT).
ok
87> From.
1
88> To.
20
89> Incr.
1
90> Incr2.
2
91> List.
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
92> ListT = [X || [X|Y] <- List, ((hd(Y) == X + Incr) or (Y == []))].
[]
93> f(ListT).
ok
94> ListT = [X || [X|Y] <- List, begin ((hd(Y) == X + Incr) or (Y == [])) end].
[]
95> f(ListT).
ok
96> ListT = [X || [X|Y] <- List, ((hd(Y) = X + Incr) or (Y = []))].
* 1: illegal pattern
97> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) or (Y == [])].
[]
98> f(ListT).
ok
99> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) orelse (Y == [])].
[]
100> f(ListT).
ok
101> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) : (Y == [])].
* 1: illegal expression
102> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) , (Y == [])].
[]
103> f(ListT).
ok
104> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) and (Y == [])].
[]
105> f(ListT).
ok
106> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) orelse (Y == [])].
[]
107> f(ListT).
ok
108> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) orelse (Y == [])].
[]
109> f(ListT).
ok
110> ListT = [X || [H|T] <- List, (hd(T) == H + Incr) orelse (T == []), X <- H].
[]
111> f(ListT).
ok
112> ListT = [X || [H|T] <- List, (hd(T) == H + Incr) orelse (T == [])].
* 1: variable 'X' is unbound
113> ListT = [X || [X|Y] <- List, (hd(Y) == X + Incr) orelse (Y == [])].
[]
114> f(ListT).
ok
115> ListT = [X || X <- List].
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
116> f(ListT).
ok
117> ListT = [X || X <- List, X > 10].
[11,12,13,14,15,16,17,18,19,20]
118> f(ListT).
ok
119> ListT = [X || [X|Y] <- List, (Y == [])].
[]
120> ListT = [X || [X|[Y]] <- List, (Y == [])].
[]
121> f(ListT).
ok
122> ListT = [X || [X|[Y|[]]] <- List, (Y == [])].
[]
123> f(ListT).
ok
124> ListT = [X || [X|Y] <- List, (Y == [])].
[]
125> f(ListT).
ok
126> ListT = [X || [X|Y] <- List].
[]
127> ListT = [X || X <- List, [_|Y] <- List].
[]
128> f(ListT).
ok
129> ListT = [X || X <- List].
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
130> f(ListT).
ok
131> ListT = [X | X <- List].
* 1: syntax error before: '<-'
131> f(ListT).
ok
132> ListT = [X || [X|_] <- List].
[]
133> ListT = [X || [X] <- List].
[]
134> ListT = [X || X <- List].
** exception error: no match of right hand side value 
                    [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
135> f(ListT).
ok
136> ListT = [X || X <- List].
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
137> ListT = [X || [H|T] <- List, X <- H].
** exception error: no match of right hand side value []
138> f(ListT).
ok
139> ListT = [X || [H|T] <- List, X <- H].
[]
140> f(ListT).
ok
141> ListT = [X || [H|T] <- List, X == H].
* 1: variable 'X' is unbound
142> ListT = [X || [H|T] == List, X <- H].
* 1: variable 'H' is unbound
143> ListT = [X || [H|T] = List, X <- H].
** exception error: bad filter [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,
                                19,20]
144> f(ListT).
ok
145> ListT = [X || X <- ([H|T] = List, (hd(T) == H + Incr) orelse (T == []))].
* 1: syntax error before: ','
145> ListT = [X || X <- ([H|T] = List, (hd(T) = H + Incr) orelse (T = []))].
* 1: syntax error before: ','
145> ListT = [X || X <- ([H|T] <- List, (hd(T) = H + Incr) orelse (T = []))].
* 1: syntax error before: '<-'
145> ListT = [X || L <- ([H|T] <- List, (hd(T) = H + Incr) orelse (T = [])), X <- L].
* 1: syntax error before: '<-'
145> ListT = [X || L <- List, (hd(T) = H + Incr) orelse (T = []), X <- L].
* 1: variable 'H' is unbound
146> ListT = [X || X <- List, (hd(tl(List)) = hd(List) + Incr) orelse (hd(tl(List)) = []), X <- L].
* 1: illegal pattern
147> ListT = [X || X <- List, (hd(tl(List)) = hd(List) + Incr) orelse (hd(tl(List)) = [])].
* 1: illegal pattern
148> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr) orelse (hd(tl(List)) == [])].
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
149> f(List).
ok
150> f(List).
ok
151> List = lists:seq(From,To,Incr).
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
152> f(List).
ok
153> List = lists:seq(From,To,Incr2).
[1,3,5,7,9,11,13,15,17,19]
154> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr) orelse (hd(tl(List)) == [])].
** exception error: no match of right hand side value []
155> f(ListT).
ok
156> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr) orelse (hd(tl(List)) == [])].
[]
157> f(ListT).
ok
158> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr2) orelse (hd(tl(List)) == [])].
[1,3,5,7,9,11,13,15,17,19]
159> f(List).
ok
160> f(ListT).
ok
161> List = [1,3,5,8,9,11,13].
[1,3,5,8,9,11,13]
162> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr2) orelse (hd(tl(List)) == [])].
[1,3,5,8,9,11,13]
163> f(ListT).
ok
164> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr2) or (hd(tl(List)) == [])].
[1,3,5,8,9,11,13]
165> f(ListT).
ok
166> ListT = [X || X <- List and (hd(tl(List)) == hd(List) + Incr2) or (hd(tl(List)) == [])].
** exception error: bad argument
     in operator  and/2
        called as [1,3,5,8,9,11,13] and true
167> f(ListT).
ok
168> ListT = [X || X <- List, (hd(tl(List)) == hd(List) + Incr2) and (hd(tl(List)) == [])].
[]
169> f(ListT).
ok
170> ListT = [X || X <- List, (hd(tl(List)) = hd(List) + Incr2) or (hd(tl(List)) = [])].
* 1: illegal pattern
171> ListT = [X || X <- List, (hd(tl(List)) == []) or (hd(tl(List)) == hd(List) + Incr2)].
[1,3,5,8,9,11,13]
172> ListT = [X || X <- List, (hd(tl(List)) = hd(List) + Incr2) or (hd(tl(List)) = [])].
* 1: illegal pattern
173> f(ListT).
ok
174> ListT = [X || X <- List, (hd(tl(List)) == []) or (hd(tl(List)) == hd(List) + Incr2)].
[1,3,5,8,9,11,13]
175> f(ListT).
ok
176> ListT = [X || X <- List, (hd(tl(List)) == []) or (hd(tl(List)) == hd(List) + Incr2)].
[1,3,5,8,9,11,13]
177> hd(tl(List)).
3
178> hd(List).
1
179> Incr2.
2
180> hd(tl(List)) == hd(List) + Incr2.
true
181> ListT = [X || X <- List, hd(tl(List)) == [] or hd(tl(List)) == hd(List) + Incr2].
* 1: syntax error before: '=='
181> f(ListT).
ok
182> ListT = [X || X <- List, (hd(tl(List)) == []) or (hd(tl(List)) == X + Incr2)].
[1]
183> List.
[1,3,5,8,9,11,13]
184> f(ListT).
ok
185> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
186> f(ListT).
ok
187> ListT = [X || X <- List, tl(List) == [] or hd(tl(List)) == (X + Incr2)].
* 1: syntax error before: '=='
187> ListT = [X || X <- List, tl(List) = [] or hd(tl(List)) = (X + Incr2)].
* 1: illegal pattern
188> f(ListT).
ok
189> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
190> f(ListT).
ok
191> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + 2)].
[1]
192> f(ListT).
ok
193> f(ListT).
ok
194> Inrc2.
* 1: variable 'Inrc2' is unbound
195> Incr2.
2
196> ListT = [X || X <- List, ((tl(List) == []) or (hd(tl(List)) == X + Incr2))].
[1]
197> f(ListT).
ok
198> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
199> f(ListT).
ok
200> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
201> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
202> f(ListT).
ok
203> ListT = [X || X <- List, (tl(List) == []) and (hd(tl(List)) == X + Incr2)].
[]
204> f(ListT).
ok
205> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
206> f(ListT).
ok
207> ListT = [X | X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
* 1: syntax error before: '<-'
207> f(ListT).
ok
208> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
209> f(ListT).
ok
210> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(X)) == X + Incr2)].
[]
211> f(ListT).
ok
212> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
213> f(ListT).
ok
214> ListT = [X || X <- List, (tl(X) == []) or (hd(tl(List)) == X + Incr2)].
[]
215> f(ListT).
ok
216> ListT = [X || X <- List, (tl(List) == []) or (hd(tl(List)) == X + Incr2)].
[1]
217> f(ListT).
ok
218> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
219> f(ListT).
ok
220> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
221> List.
[1,3,5,8,9,11,13]
222> f(ListT).
ok
223> ListT = [X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
224> List.
[1,3,5,8,9,11,13]
225> Incr.
1
226> f(Incr).
ok
227> Incr = 2.
2
228> List.
[1,3,5,8,9,11,13]
229> Incr.
2
230> List2=[X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
** exception error: no match of right hand side value [1]
231> f(List2)
.
ok
232> List.
[1,3,5,8,9,11,13]
233> Incr.
2
234> List2=[X || X <- List, (tl(List) == []) orelse (hd(tl(List)) == X + Incr2)].
[1]
235> f(ListT).
ok
236> c(assignment5).
assignment5.erl:31: syntax error before: 'when'
assignment5.erl:22: function check_incr/2 undefined
assignment5.erl:22: Warning: variable 'List2' is unused
error
237> c(assignment5).
assignment5.erl:31: illegal guard expression
assignment5.erl:22: Warning: variable 'List2' is unused
assignment5.erl:29: Warning: variable 'Incr' is unused
assignment5.erl:33: Warning: variable 'Incr' is unused
assignment5.erl:33: Warning: variable 'X' is unused
assignment5.erl:33: Warning: variable 'Y' is unused
error
238> 