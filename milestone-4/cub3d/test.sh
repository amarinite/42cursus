#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

TOTAL=0
PASSED=0
FAILED=0

echo "======================================"
echo "Testing Wrong Maps"
echo "======================================"
echo ""

if [ ! -f "./cub3d" ]; then
	echo -e "${RED}Error: ./cub3d executable not found${NC}"
	echo "Please compile the project first"
	exit 1
fi

if [ ! -d "maps/wrongmaps" ]; then
	echo -e "${RED}Error: maps/wrongmaps directory not found${NC}"
	exit 1
fi

for map in maps/wrongmaps/*.cub; do
	if [ -f "$map" ]; then
		TOTAL=$((TOTAL + 1))
		echo -e "${YELLOW}Testing:${NC} $map"
		
		OUTPUT=$(./cub3d "$map" 2>&1)
		
		if echo "$OUTPUT" | grep -q "Error:"; then
			echo -e "${GREEN}✓ PASSED${NC} - Error detected: $OUTPUT"
			PASSED=$((PASSED + 1))
		else
			echo -e "${RED}✗ FAILED${NC} - No error message or program didn't exit with error"
			echo "  Output: $OUTPUT"
			FAILED=$((FAILED + 1))
		fi
		echo ""
	fi
done

echo "======================================"
echo "Test Summary"
echo "======================================"
echo "Total tests: $TOTAL"
echo -e "${GREEN}Passed: $PASSED${NC}"
if [ $FAILED -gt 0 ]; then
	echo -e "${RED}Failed: $FAILED${NC}"
else
	echo -e "${GREEN}Failed: $FAILED${NC}"
fi
echo ""

if [ $FAILED -gt 0 ]; then
	exit 1
else
	exit 0
fi