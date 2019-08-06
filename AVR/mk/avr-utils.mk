# utility targets
.PHONY:	load
load:	$(TARGET).hex ## Load hex file using avrdude
	$(DUDE) $(DUDECONF) $(UFLAGS) -Uflash:w:$(TARGET).hex:i

.PHONY:	clean
clean: ## remove build artifacts
	$(RM) *.hex *.lst  *.elf $(OBJS)