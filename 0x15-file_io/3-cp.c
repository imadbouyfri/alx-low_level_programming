#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error(const char* message, const char* file_path, int exit_code) {
    dprintf(STDERR_FILENO, message, file_path);
        exit(exit_code);
	}

	int main(int argc, char* argv[]) {
	    const char* file_from;
	        const char* file_to;
		    int fd_from, fd_to;
		        char buffer[BUFFER_SIZE];
			    ssize_t bytes_read, bytes_written;

			        if (argc != 3) {
				        error("Usage: %s file_from file_to\n", argv[0], 97);
					    }

					        file_from = argv[1];
						    file_to = argv[2];

						        fd_from = open(file_from, O_RDONLY);
							    if (fd_from == -1) {
							            error("Error: Can't read from file %s\n", file_from, 98);
								        }

									    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
									        if (fd_to == -1) {
										        error("Error: Can't write to %s\n", file_to, 99);
											    }

											        while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
												        bytes_written = write(fd_to, buffer, bytes_read);
													        if (bytes_written == -1) {
														            error("Error: Can't write to %s\n", file_to, 99);
															            }

																            if (bytes_written < bytes_read) {
																	                error("Error: Incomplete write to %s\n", file_to, 99);
																			        }
																				    }

																				        if (bytes_read == -1) {
																					        error("Error: Can't read from file %s\n", file_from, 98);
																						    }

																						        if (close(fd_from) == -1) {
																							        error("Error: Can't close fd %d\n", file_from, 100);
																								    }

																								        if (close(fd_to) == -1) {
																									        error("Error: Can't close fd %d\n", file_to, 100);
																										    }

																										        return 0;
																											}
