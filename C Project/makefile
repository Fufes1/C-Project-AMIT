#use a hash to create a commment

#main.exe:
#	$(C_compiler) $(project_name).c -E -o $(project_name).i
#	@echo "*****preprocessing done******"
#	$(C_compiler) $(project_name).c -S -o $(project_name).s
#	@echo "*****Compiler done******"
#	$(C_compiler) $(project_name).c -s -o $(project_name).o
#	@echo "*****assembly done******"
#	$(C_compiler) $(project_name).c -o $(project_name).exe
#	@echo "***** Ready to execute *****"
#	@./$(project_name).exe

#creating general file
project_name = SDB_APP
supporting_file = SDB
C_compiler = gcc

$(project_name).exe: $(project_name).o $(supporting_file).o
	$(C_compiler) $(project_name).c -o $(project_name).exe	
	$(C_compiler) $(supporting_file).c -o $(supporting_file).exe
	@echo "*****Linking Done******"
	@echo "*****Ready to Execute******"
	./$(project_name).exe

$(project_name).o: $(project_name).s
	$(C_compiler) $(project_name).c -c -o $(project_name).o
	$(C_compiler) $(supporting_file).c -c -o $(supporting_file).o
	@echo "*****Assembling Done******"

$(project_name).s: $(project_name).i
	$(C_compiler) $(project_name).c -S -o $(project_name).s
	$(C_compiler) $(supporting_file).c -S -o $(supporting_file).s
	@echo "*****Complining Done******"

$(project_name).i: $(project_name).c $(supporting_file).c
	$(C_compiler) $(project_name).c -E -o $(project_name).i
	$(C_compiler) $(supporting_file).c -E -o $(supporting_file).i
	@echo "*****Preprocessing Done******"






clean_exe: 
	rm ./$(project_name).exe

clean:
	rm $(project_name).i $(project_name).s $(project_name).o $(project_name).exe
	rm $(supporting_file).i $(supporting_file).s $(supporting_file).o $(supporting_file).exe 
	@echo "Euthanization Done"

