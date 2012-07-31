n = 1:10;
u = 1-n+n.^2-n.^3+n.^4-n.^5+n.^6-n.^7+n.^8-n.^9+n.^10;
%n = 1:3;
%u = n.^3;

sumfit = 0;
fit = zeros(1,length(n));

for deg=1:length(n);
    p  = polyfit(n(1:deg), u(1:deg), deg-1);
    fit(deg) = polyval(p,deg+1);
    sumfit = sumfit + fit(deg);
end
disp(fit);
disp(sumfit);