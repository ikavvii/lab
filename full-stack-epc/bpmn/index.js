const { ZBClient } = require('zeebe-node');

// 1. Connection settings
// If using Camunda 8 SaaS, use environmental variables or pass credentials here.
// If using Self-Managed (Local Docker), this defaults to localhost:26500 automatically.
const zbc = new ZBClient(); 

console.log("Job worker started... waiting for jobs.");

// 2. Validate Order Worker
zbc.createWorker({
	taskType: 'validate-order',
	taskHandler: async (job) => {
		console.log(`[1] Validating order for Process Instance: ${job.processInstanceKey}`);
		
        // Complete the job
		return job.complete();
	}
});

// 3. Process Payment Worker (The Decision Maker)
zbc.createWorker({
	taskType: 'process-payment',
	taskHandler: async (job) => {
		// Simulate Random Payment Success/Failure
		const isSuccess = Math.random() < 0.5;
		
		console.log(`[2] Processing Payment... Result: ${isSuccess ? 'APPROVED' : 'DECLINED'}`);

		// Pass variable back to Zeebe for the Gateway Decision
		return job.complete({
			paymentSuccess: isSuccess
		});
	}
});

// 4. Ship Goods Worker
zbc.createWorker({
	taskType: 'ship-goods',
	taskHandler: async (job) => {
		console.log(`[3A] Payment verified. Shipping goods...`);
		return job.complete();
	}
});

// 5. Send Rejection Worker
zbc.createWorker({
	taskType: 'send-rejection',
	taskHandler: async (job) => {
		console.log(`[3B] Payment failed. Sending rejection email...`);
		return job.complete();
	}
});