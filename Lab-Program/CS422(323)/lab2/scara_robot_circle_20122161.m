%% scara_robot_circle_20122161.m
% 
% This Matlab script provides the starter code for Programming assignment 2 used at Maynooth University. The code was modified from
% open source codes written by Prof. Katherine J. Kuchenbecker.
%
% Student Name: Hanlin CAI
%
% Change the name of this file to replace "starter" with your MU ID number.  For
% example, scara_robot_circle_20122161
%% SETUP

% Clear all variables from the workspace.
clear all

% Clear the console, so you can more easily find any errors that may occur.
clc

% Input your name as a string.
student_name = 'Hanlin CAI';

% Define our time vector.
tStart = 0;   % The time at which the simulation starts, in seconds.
tStep = 0.04; % The simulation's time step, in seconds.
tEnd = 2*pi;    % The time at which the simulation ends, in seconds.
t = (tStart:tStep:tEnd)';  % The time vector (a column vector).

% Set whether to animate the robot's movement and how much to slow it down.
pause on;  % Set this to off if you don't want to watch the animation.
GraphingTimeDelay = 0.01; % The length of time that Matlab should pause between positions when graphing, if at all, in seconds.


%% ROBOT PARAMETERS

% This problem is about the first three joints (RRP) of a SCARA
% manipulator.  This robot's forward kinematics are worked out on pages 91
% to 93 of the SHV textbook, though we are ignoring the fourth joint (the
% wrist).

% Define robot link lengths.
a1 = 1.0; % Distance between joints 1 and 2, in meters.
a2 = 0.7; % Distance between joints 2 and 3, in meters.


%% DEFINE CIRCULAR MOTION

% We want the SCARA to draw a vertical circle parallel to the x-z plane.

% Define the radius of the circle.
radius = .8; % meters

% Define the y-value for the plane that contains the circle.
y_offset = -1; % meters

% Define the x and z coordinates for the center of the circle.
x_center = -.5; % meters
z_center = .2; % meters

% Set the desired x, y, and z positions over time given the circle parameters.
ox_history = x_center + radius * sin(t);
oy_history = y_offset * ones(size(t));
oz_history = z_center + radius * cos(t);


%% SIMULATION

% Notify the user that we're starting the animation.
disp('Starting the animation.')

% Show a message to explain how to cancel the simulation and graphing.
disp('Click in this window and press control-c to stop the code.')

% Initialize a matrix to hold the position of the robot's tip over time.
% The first row is the x-coordinate, second is y, and third is z, all in
% the base frame.  You are welcome to make this 4 rows if you want to use
% the homogeneous representation for points.  It has the same number of
% columns as t has rows, one tip position for every time step in the
% simulation.  We keep track of this history so we can trace out the
% trajectory of where the robot's tip has been.
tip_history = zeros(3,length(t));

% Step through the time vector to animate the robot.
for i = 1:length(t)
    
    % Pull the current values of ox, oy, and oz from their histories. 
    ox = ox_history(i);
    oy = oy_history(i);
    oz = oz_history(i);
    
    % Do your calculations. If you do things in a straightforward way, all
    % of your code should be between the two lines of stars.
    % *******************************************************************
    
    % Calculate theta1, theta2, and d3 given the robot's parameters (a1 and
    % a2) and the current desired position for its tip ([ox oy oz]').

    % For now, just set all three joint coordinates to zero.  You should change this.
    
    cos_theta2 = (ox^2 + oy^2 - a1^2 - a2^2) / (2*a1*a2);
    temp = sqrt(1 - cos_theta2^2);
    theta2 = atan2(temp, cos_theta2);
    theta1 = atan2(oy,ox) - atan2( a2*sin(theta2), a1 + a2*cos(theta2));
    d3 = -oz;
    
    % This program is lastly modified by Hanlin CAI in 2022/12/10.
    
    % *******************************************************************
    % All your calculations should be done by here.  You should have set
    % the values of theta1, theta2, and d3 based on a1, a2, ox, oy, and oz.

    % Use provided .p function to calculate the points of the robot that we
    % should plot to show in the animation.
    points_to_plot = scara_robot_fk(a1, a2, theta1, theta2, d3);
    
    % Grab the final plotted point for the trajectory graph.
    tip_history(:,i) = points_to_plot(1:3,end);

    % Check if this is the first time we are plotting.
    if (i == 1)
        % Open figure 1.
        figure(1);
        
        % The first time, plot the robot points and keep a handle to the plot.
        % This is a 3D plot with dots at the points and lines connecting
        % neighboring points, made thicker, with big dots, in dark gray.
        hrobot = plot3(points_to_plot(1,:),points_to_plot(2,:),points_to_plot(3,:),'.-','linewidth',5,'markersize',20,'color',[.3 .3 .3]);
        
        % Also plot the tip position of the robot, using hold on and hold
        % off, also keeping a handle to the plot so we can update the data
        % points later.
        hold on;
        htip = plot3(tip_history(1,i),tip_history(2,i),tip_history(3,i),'r.');
        hold off;

        % Label the axes.
        xlabel('X (m)');
        ylabel('Y (m)');
        zlabel('Z (m)');

        % Turn on the grid and the box.
        grid on;
        box on;

        % Set the axis limits.
        axis([-2 2 -2 2 -2 2])

        % Set the axis properties for 3D visualization, which makes one
        % unit the same in every direction, and enables rotation.
        axis vis3d;

        % Put text on the plot to show how much time has elapsed.  The text
        % is centered.
        htime = text(1,1,1,sprintf('t = %.2f s',t(i)),'horizontalAlignment','center');

        % Add a title including the student's name.
        title(['SCARA Robot Drawing a Circle by ' student_name]);
    else
        % Once the animation has been set up, we don't need to reformat the
        % whole plot.  We just set the data to the correct new values for
        % the robot animation, the tip history, and the text showing the
        % elapsed time.
        set(hrobot,'xdata',points_to_plot(1,:),'ydata',points_to_plot(2,:),'zdata',points_to_plot(3,:))
        set(htip,'xdata',tip_history(1,1:i),'ydata',tip_history(2,1:i),'zdata',tip_history(3,1:i))
        set(htime,'string', (sprintf('t = %.2f s',t(i))));
    end
    
    % Pause for a short duration so that the viewer can watch animation evolve over time.
    pause(GraphingTimeDelay)
    
end

disp('Done with the animation.')
