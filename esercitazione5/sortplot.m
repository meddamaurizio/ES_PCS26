%% NOTA SULL'USO DELL'AI
% strumenti di inteligenza artificiale sono stati usati
% per la realizzazione di questo script

%% Sorting Algorithms Benchmarking Plotter
% This script reads multiple .txt files from a folder.
% Format per file: [x <y_i>] \\ 
% x: Array dimension (grows exponentially)
% y_i: Execution time for algorithm i

clear; clc; close all;

folderPath = 'tempi'; 
filePattern = fullfile(folderPath, '*.txt');
txtFiles = dir(filePattern);

if isempty(txtFiles)
    error('No .txt files found in the specified folder.');
end

% 2. Initialize data storage
% We aggregate all rows into a single matrix to handle varying x values.
combinedData = []; 

fprintf('Reading %d files...\n', length(txtFiles));

for k = 1:length(txtFiles)
    fullFileName = fullfile(folderPath, txtFiles(k).name);
    
    % Read numeric data from the file
    data = readmatrix(fullFileName); 
    
    % Concatenate data vertically
    combinedData = [combinedData; data]; 
end

% 3. Calculate Average across all files
% Group by unique x values (first column) and calculate the mean of times
[uniqueX, ~, groupIdx] = unique(combinedData(:, 1));
avgData = zeros(length(uniqueX), size(combinedData, 2));

for i = 1:length(uniqueX)
    avgData(i, :) = mean(combinedData(groupIdx == i, :), 1);
end

x = avgData(:, 1);          % Array dimensions
y_times = avgData(:, 2:end); % Times for algorithms 1 to N

% 4. Create the Plot
figure('Color', 'w', 'Name', 'Sorting Algorithm Performance');
hold on; grid on;

% Define algorithm names for the legend
algoNames = {'BubbleSort', 'InsertionSort', 'SelectionSort', 'MergeSort', 'QuickSort', 'std::sort()', 'mySort'};


for i = 1:size(y_times, 2)
    loglog(x, y_times(:, i), '-o', 'LineWidth', 1.5, 'MarkerSize', 2);
end

% 5. Formatting
set(gca, 'XScale', 'log', 'YScale', 'log'); % Ensure log-log scale
xlabel('Dimensione del vettore (n)');
ylabel('Tempo (secondi)');
title('Algoritmi di Ordinamento');
legend(algoNames, 'Location', 'northwest');

% Optional: Set specific X-ticks if x grows by powers of 2
xticks(x); 
xtickformat('%g');
