function A = dh_20122161(a, alpha, d, theta)

% This function calculates the four-by-four transformation matrix A for a
% given set of DH parameters: a, alpha, d, and theta.  The angles are in
% degrees, so be sure to use appropriate trigonometric functions (sind and
% cosd rather than sin and cos).

% IMPORTANT: change the name of this file and the function definition on
% the first line of this file to include your MU student number rather than
% "starter".  The name of the file and the line above should match.

% Calculate the A matrix that corresponds to a, alpha, d, and theta.  
% Your code should go here.  For now, we are just filling each column with
% a parameter, but you will definitely want to change this.
% This program is lastly modified by Hanlin CAI in 2022/12/10.

A = [ cosd(theta) -sind(theta)*cosd(alpha) sind(theta)*sind(alpha) a*cosd(theta); ...
      sind(theta) cosd(theta)*cosd(alpha) -cosd(theta)*sind(alpha) a*sind(theta); ...
      0 sind(alpha) cosd(alpha) d; ...
      0 0 0 1];