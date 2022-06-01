run:
	@./script.sh
	@echo ""
	@echo "If you want to delete all quads, just use: make clear"
	@echo "Optionaly, if you, really, want you may use ./script.sh clear"
clear:
	@./script.sh $@
