.PHONY: clean All

All:
	@echo "----------Building project:[ LD30 - Debug ]----------"
	@$(MAKE) -f  "LD30.mk"
clean:
	@echo "----------Cleaning project:[ LD30 - Debug ]----------"
	@$(MAKE) -f  "LD30.mk" clean
