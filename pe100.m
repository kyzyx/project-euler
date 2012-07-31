% From the first four solutions m/n: 3/4, 15/21, 85/120, 493/697
% Assume am + bn + c = m' and dm + en + f = n'
% Then solve the following matrices

A = [ 3   4  1
     15  21  1 
     85 120  1];
mp = A\[15
        85
        493];
np = A\[21
        120
        697];

m = 3;
n = 4;

while n < 10^12
    tmpm = sum(mp'.*[m n 1]);
    tmpn = sum(np'.*[m n 1]);
    m = tmpm; n = tmpn;
end
format long;
m