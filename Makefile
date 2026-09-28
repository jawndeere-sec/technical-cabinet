.PHONY: verify clean artifact-manifest

verify:
	@$(MAKE) -C cabinets/cpp verify

clean:
	@$(MAKE) -C cabinets/cpp clean

artifact-manifest:
	@$(MAKE) -C cabinets/cpp artifact-manifest

