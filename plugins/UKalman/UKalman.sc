UKalman : UGen {
	*kr { |input, smoothness, rapidness|
		^this.multiNew('control', input, smoothness, rapidness);
	}
	checkInputs {
		/* TODO */
		^this.checkValidInputs;
	}
}
