function interpol(x0,y0,x1,y1,x0_,y0_,x1_,y1_,t0,t1) 

A = [t0^3, t0^2, t0, 1; 
    t1^3 , t1^2, t1, 1;
    3*t0^2, 2*t0, 1, 0;
    3*t1^2, 2*t1, 1, 0];

B = [y0;y1;y0_;y1_];
y=inv(A)*B;

B = [x0;x1;x0_;x1_];
x=inv(A)*B;

 syms t
 U = x(1) * t^3 + x(2)*t^2 + x(3)*t + x(4)

 syms t
 V = y(1) * t^3 + y(2)*t^2 + y(3)*t + y(4)

hold on
plot(x0 , y0,'r.','MarkerSize', 20);
plot(x1 , y1,'r.','MarkerSize', 20);
quiver(x0,y0,x0_,y0_,0.05);
quiver(x1,y1,x1_,y1_,0.05);
fplot(U,V,[t0 t1]);
end






