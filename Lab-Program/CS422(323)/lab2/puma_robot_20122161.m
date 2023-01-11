%% puma_robot_20122161.m
% 
% This Matlab script provides the starter code for Programming assignment 2 used at Maynooth University. The code was modified from
% open source codes written by Prof. Katherine J. Kuchenbecker.
%
% Student Name: Hanlin CAI
%
% Change the name of this file to replace "starter" with your MU ID number.  For
% example, puma_robot_20212161

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
tEnd = 5;     % The time at which the simulation ends, in seconds.
t = (tStart:tStep:tEnd)';  % The time vector (a column vector).

% Set whether to animate the robot's movement and how much to slow it down.
pause on;  % Set this to off if you don't want to watch the animation.
GraphingTimeDelay = 0.01; % The length of time that Matlab should pause between positions when graphing, if at all, in seconds.


%% ROBOT PARAMETERS

% This problem is about the PUMA 260 robot, a 6-DOF manipulator.

% Define the robot's measurements.  These correspond to the diagram in the
% homework and are constant.
a = 13.0; % inches
b =  3.5; % inches
c =  8.0; % inches
d =  3.0; % inches
e =  8.0; % inches
f =  2.5; % inches

%% MOTION MODES

% 0 makes the robot sit still with all joint coordinates at zero.
% i makes only joint i move, for 1 <= i <= 6.
% 7 makes all of the joints move.

% Ask the user to choose the mode of the robot motion.
motion_mode = input('Which motion mode? ');

% Start by giving all joints a history of zeros, since that is the default.
theta1_history = 0*t;
theta2_history = 0*t;
theta3_history = 0*t;
theta4_history = 0*t;
theta5_history = 0*t;
theta6_history = 0*t;

% Define standard joint velocity for motion modes.
omega = 180; % degrees / second

% Define the joint coordinates given the selected motion mode.  All joint angles areHere we are
% setting the values for all six thetas.  Each one must be a column vector
% of the same dimensions as t. 
switch motion_mode
    case 0
        disp('The robot should be stationary.')
        % All joints have already been set to zero, so we don't need to do
        % anything else here.
    case 1
        disp('The robot should be moving only joint 1.')
        theta1_history = omega*t; % Set theta1 to an interesting function.
    case 2
        disp('The robot should be moving only joint 2.')
        theta2_history = omega*t; % Set theta2 to an interesting function.
    case 3
        disp('The robot should be moving only joint 3.')
        theta3_history = omega*t; % Set theta3 to an interesting function.
    case 4
        disp('The robot should be moving only joint 4.')
        theta4_history = omega*t; % Set theta4 to an interesting function.
    case 5
        disp('The robot should be moving only joint 5.')
        theta5_history = omega*t; % Set theta5 to an interesting function.
    case 6
        disp('The robot should be moving only joint 6.')
        theta6_history = omega*t; % Set theta6 to an interesting function.
    case 7
        disp('The robot should be moving all of its joints.')
        theta1_history = -30+30*sin(2.0*t); % Set theta1 to an interesting function.
        theta2_history =  30*sin(2.2*t); % Set theta2 to an interesting function.
        theta3_history = -30*sin(2.4*t); % Set theta3 to an interesting function.
        theta4_history =  30*sin(2.0*t); % Set theta4 to an interesting function.
        theta5_history =  30*sin(2.2*t); % Set theta5 to an interesting function.
        theta6_history = -30*sin(2.4*t); % Set theta6 to an interesting function.
    otherwise
        error('Error! Unknown motion_mode')
end


%% SIMULATION

% Notify the user that we're starting the animation.
disp('Starting the animation.')

% Show a message to explain how to cancel the simulation and graphing.
disp('Click in this window and press control-c to stop the code.')

% Initialize a matrix to hold the position of the robot's tip over time.
% The first row is the x-coordinate, second is y, and third is z, all in
% the base frame. It has the same number of columns as t has rows, one tip
% position for every time step in the simulation.  We keep track of this
% history so we can trace out the trajectory of where the robot's tip has been.
tip_history = zeros(3,length(t));

% Step through the time vector to animate the robot.
for i = 1:length(t)
    
    % Pull the current values of the six joint angles from their histories.
    theta1 = theta1_history(i);
    theta2 = theta2_history(i);
    theta3 = theta3_history(i);
    theta4 = theta4_history(i);
    theta5 = theta5_history(i);
    theta6 = theta6_history(i);

    % Do your calculations, using your dh function as needed.
    % All of your code should be between the two lines of stars.  
    % *******************************************************************

    % Calculate the six A matrices using DH function.
    A1 = dh_20122161(0,90,a,theta1);
    A2 = dh_20122161(c,0,-b,theta2);
    A3 = dh_20122161(0,-90,-d,theta3);
    A4 = dh_20122161(0,90,e,theta4);
    A5 = dh_20122161(0,-90,0,theta5);
    A6 = dh_20122161(0,0,f,theta6);
    
    % Define the homogeneous representation of the origin of any frame.
    o = [0 0 0 1]';

    % Calculate the position of the origin of each frame in the base frame.
    H0_1 = A1;
    H0_2 = A1*A2;
    H0_3 = H0_2*A3;
    H0_4 = H0_3*A4;
    H0_5 = H0_4*A5;
    H0_6 = H0_5*A6;
    
    o0 = o;
    o1 = H0_1*o;
    o2 = H0_2*o;
    o3 = H0_3*o;
    o4 = H0_4*o;
    o5 = H0_5*o;
    o6 = H0_6*o;
    
    % Put the seven origin points together for plotting.
    % For now we are just plotting the origin of the base frame seven times.
    points_to_plot = [o0 o1 o2 o3 o4 o5 o6];
    
    % This program is lastly modified by Hanlin CAI in 2022/12/10.
    
    % *******************************************************************
    % All your calculations should be done by here.  You should have
    % calculated all six of the A matrices (A1 through A6) and put the
    % seven frame origins into points_to_plot in order, so that the last
    % one is the tip of the robot (frame 6).

    % Grab the final plotted point for the trajectory graph.
    tip_history(:,i) = points_to_plot(1:3,end);

    % Check if this is the first time we are plotting.
    if (i == 1)
        % Open figure 1.
        figure(1);
        
        % The first time, plot the robot points and keep a handle to the plot.
        % This is a 3D plot with dots at the points and lines connecting
        % neighboring points, made thicker, with big dots, in almost black.
        hrobot = plot3(points_to_plot(1,:),points_to_plot(2,:),points_to_plot(3,:),'.-','linewidth',7,'markersize',25,'color',[.25 .25 .125]);
        
        % Also plot the tip position of the robot, using hold on and hold
        % off, also keeping a handle to the plot so we can update the data
        % points later.
        hold on;
        htip = plot3(tip_history(1,i),tip_history(2,i),tip_history(3,i),'b.');
        hold off;

        % Label the axes.
        xlabel('X (in.)');
        ylabel('Y (in.)');
        zlabel('Z (in.)');

        % Turn on the grid and the box.
        grid on;
        box on;

        % Set the axis limits.
        axis([-20 20 -20 20 0 40])

        % Set the axis properties for 3D visualization, which makes one
        % unit the same in every direction, and enables rotation.
        axis vis3d;

        % Put text on the plot to show how much time has elapsed.  The text
        % is centered.
        htime = text(-10,10,0,sprintf('t = %.2f s',t(i)),'horizontalAlignment','center');

        % Add a title including the student's name.
        title(['PUMA 360 Robot dances with ' student_name]);
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
