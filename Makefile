.PHONY: verify clean artifact-manifest

verify:
	@./scripts/verify.sh

clean:
	@rm -rf build

artifact-manifest:
	@./scripts/manifest-artifacts.sh

