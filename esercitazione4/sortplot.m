%% NOTA SULL?USO DELL'AI
% strumenti di inteligenza artificiale sono stati usati
% per la realizzazione di questo codice

%% Sorting Algorithms Benchmarking Plotter
% This script reads multiple .txt files from a folder.
% Format per file: [x y_1 y_2 y_3 y_4]
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
% We use a Map or a flexible cell array if we aren't sure of row counts, 
% but based on your description, we can aggregate data into a 3D matrix.
allData = []; 

fprintf('Reading %d files...\n', length(txtFiles));

for k = 1:length(txtFiles)
    fullFileName = fullfile(folderPath, txtFiles(k).name);
    
    % Read numeric data from the file
    data = readmatrix(fullFileName); 
    
    % Store data to calculate average later
    % Format: [rows, columns, file_index]
    allData(:,:,k) = data; 
end

% 3. Calculate Average across all files
% mean(..., 3) averages across the 3rd dimension (the different files)
avgData = mean(allData, 3);

x = avgData(:, 1);          % Array dimensions
y_times = avgData(:, 2:end); % Times for algorithms 1 to N

% 4. Create the Plot
figure('Color', 'w', 'Name', 'Sorting Algorithm Performance');
hold on; grid on;

% Define algorithm names for the legend
algoNames = {'BubbleSort', 'InsertionSort', 'SelectionSort', 'std::sort()'};


for i = 1:size(y_times, 2)
    semilogx(x, y_times(:, i), '-o', 'LineWidth', 1.5, 'MarkerSize', 4);
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
