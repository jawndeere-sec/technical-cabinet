.PHONY: verify clean artifact-manifest

verify:
	@$(MAKE) -C cabinets/cpp verify
	@python3 scripts/verify-study-cabinets.py

clean:
	@$(MAKE) -C cabinets/cpp clean

artifact-manifest:
	@$(MAKE) -C cabinets/cpp artifact-manifest

