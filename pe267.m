f = 0.12:0.0001:0.18;
g = zeros(length(f), 1000);

for i=1:1000
    for j=1:length(f)
        g(j,i) = ((1+f(j)*2)^i)*((1-f(j))^(1000-i));
    end
end

h = g>1000000000 | g==inf;
for i=1:1000
    h(:,i) = h(:,i)*nchoosek(1000,i);
end
func = sum(h');